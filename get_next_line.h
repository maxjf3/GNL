/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 23:00:15 by mjardin           #+#    #+#             */
/*   Updated: 2026/11/03 21:06:42 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFE_SIZE 42
#endif

int		get_next_line_size(char *buffer, int i);
char	*init_buffer(int fd, int *first_time);
char	*get_next_line(int fd);
int		ft_strlen(char *s);

#endif