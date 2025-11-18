/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:29:07 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/18 20:03:47 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[0])
	{
		line = join_move(line, buffer);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	while (!ft_strchr(line, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(line), NULL);
		if (read_bytes == 0)
			return (line);
		buffer[read_bytes] = 0;
		line = join_move(line, buffer);
	}
	return (line);
}

/* int main()
{
	int fd = open("file.txt", O_RDWR);
	char *line = NULL;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return 0;
} */
