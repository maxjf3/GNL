/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:23:38 by mjardin           #+#    #+#             */
/*   Updated: 2026/11/03 21:08:12 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*init_buffer(int fd, int *first_time)
{
	char	*buffer;
	int		i;
	
	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(buffer);
			return (NULL);
		}
		read(fd, buffer, BUFFER_SIZE);
	while (i < BUFFER_SIZE + 1)
		i++;
	buffer[i] = '\0';
	(*first_time) += 1;
	return (buffer);
}

int	get_next_line_size(char *buffer, int i)
{
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}