/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 22:57:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/11/03 21:05:39 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	static int	first_time;
	static int	index_buffer;
	int			index_res;
	char		*res;

	index_res = 0;
	if (fd <= 0)
		return (NULL);
	if (first_time <= 0)
		buffer = init_buffer(fd, &first_time);
	res = malloc(get_next_line_size(buffer, index_buffer));
	while (buffer[index_buffer])
	{
		if (index_buffer == ft_strlen(buffer))
		{
			free(buffer);
			return (NULL);
		}
		if (buffer[index_buffer] == '\n')
		{
			res[index_res] = buffer[index_buffer];
			index_buffer++;
			return (res);
		}
		res[index_res] = buffer[index_buffer];
		index_buffer++;
		index_res++;
	}
	return (res);
}