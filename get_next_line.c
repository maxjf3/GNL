/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 22:57:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/31 16:05:12 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*res;
	int		i;
	int		buf_size;

	i = 0;
	buf_size = 0;
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	while(buffer[buf_size])
		buf_size++;
	res = malloc(buf_size * sizeof(char));
	if (!res)
		return (NULL);
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
		{
			res[i] = buffer[i];
			free(buffer);
			return (res);
		}
		else
			res[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (res);
}
