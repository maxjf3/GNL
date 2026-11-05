/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:23:38 by mjardin           #+#    #+#             */
/*   Updated: 2026/11/05 21:42:51 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc((s1_len + s2_len) + 1);
	if (!res)
		return (NULL);
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		res[i++] = s2[j];
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
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
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
			break ;
		}
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_clean_save(char *s)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (i == ft_strlen(s))
		return (ft_free(s, 0));
	res = malloc((ft_strlen(s) - i) + 1);
	if (!res)
		return (ft_free(s, 0));
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

char	*ft_free(char *buffer, char **save)
{
	if (buffer)
		free(buffer);
	if (save)
	{
		free(*save);
		*save = NULL;
	}
	return (NULL);
}
