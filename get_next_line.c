/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 22:57:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/11/05 11:34:22 by max              ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*line;
	int			bytes;
	char		*tmp;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
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
			tmp = ft_strjoin(save, buffer);
			if (!tmp)
				return (ft_free(buffer, &save));
			free(save);
			save = tmp;
		}
		if (bytes == -1)
			return (ft_free(buffer, &save));
	}
	if ((!save || save[0] == '\0'))
		return (ft_free(buffer, &save));
	line = ft_get_line(save);
	if ((!line))
		return (ft_free(buffer, &save));
	save = ft_clean_save(save);
	free(buffer);
	return (line);
}
