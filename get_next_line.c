/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 22:57:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/11/02 16:52:00 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_get_buffer_size(char *buffer, int *buf_index)
{
	int	buf;

	buf = (*buf_index);
	while(buffer[buf] && buffer[buf] != '\n')
		buf++;
	return (buf);
}
char	*get_next_line(int fd)
{
	char			*buffer;
	int				i;
	char			*res;
	int				buf_size;
	static int		buf_index;

	i = 0;
	buf_size = 0;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);	
	read(fd, buffer, BUFFER_SIZE);
	buf_size = ft_get_buffer_size(buffer, &buf_index);
	res = malloc(buf_size * sizeof(char));
	if (!res)
		return (NULL);
	while (i <= buf_size)
	{
		res[i] = buffer[buf_index];
		i++;
		buf_index++;
	}
	free(buffer);
	return (res);
}
