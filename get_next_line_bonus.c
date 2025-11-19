/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:57:44 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/19 14:01:21 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	line = NULL;
	if (buffer[fd][0])
	{
		line = join_move(line, buffer[fd]);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	while (!ft_strchr(line, '\n'))
	{
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(line), NULL);
		if (read_bytes == 0)
			return (line);
		buffer[fd][read_bytes] = 0;
		line = join_move(line, buffer[fd]);
	}
	return (line);
}
