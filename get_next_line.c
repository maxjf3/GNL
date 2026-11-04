/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 22:57:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/11/04 17:06:30 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_got_nl(char *save)
{
	while (*save)
	{
		if (*save == '\n')
			return (1);
		save++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	while (i < ft_strlen((char *)s1))
	{
		res[i] = s1[i];
		i++;
	}
	while (j < ft_strlen((char *)s2))
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		if (res[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_del_line(char *s)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	dst = malloc(i + 1);
	if (!dst)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dst[j] = s[j];
		j++;
	}
	return (dst);
}

char	*ft_clean_save(char *s)
{
	size_t		i;
	size_t		j;
	char	*res;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	if (i == ft_strlen(s))
	{
		free(s);
		return (NULL);
	}
	res = malloc((ft_strlen(s) - i) + 1);
	if (!res)
	{
		free(s);
		return (NULL);
	}
	while (s[i])
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	free(s);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*line;
	int			bytes;
	

	bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	if (!save)
	{
		save = malloc(1);
		if (!save)
		{
			free(buffer);
			return (NULL);
		}
		save[0] = '\0';
	}

	while (!ft_got_nl(save) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			save = ft_strjoin(save, buffer);
		}
		if (bytes == -1)
		{
			free(buffer);
			free(save);
			save = NULL;
			return (NULL);
		}
	}

	if ((!save || save[0] == '\0') && bytes == 0)
	{
		free(buffer);
		free(save);
		save = NULL;
		return (NULL);
	}
	line = ft_get_line(save);
	save = ft_clean_save(save);
	
	free(buffer);
	return (line);
}