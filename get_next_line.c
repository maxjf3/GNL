/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 22:57:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/11/04 02:34:30 by max              ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(ft_strlen(s) * sizeof(char));
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
			(ft_strlen(s1) + ft_strlen(s2)));
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

char	*ft_get_res(char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break;
		i++;
	}
	res = malloc(i + 1);
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

int	ft_strdel(char *s)
{
	int		i;

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
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*res;
	int			bytes;
	
	if (!save || save[0] == '\0')
	{
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		save = ft_strdup(buffer);
	}
	while (!ft_got_nl(buffer) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		save = ft_strjoin(save, buffer);
	}
	res = ft_get_res(save);
	save = ft_strdup(save + ft_strdel(save));
	return (res);
}