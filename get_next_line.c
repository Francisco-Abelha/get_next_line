/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:29:07 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/14 20:44:54 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		read_size;
	char		*newline_pos;
	size_t		len;

	line = NULL;
	if (buffer[0])
	{
		newline_pos = ft_strchr(buffer, '\n');
		if (newline_pos)
		{
			len = newline_pos;
			return (line);
		}
		else
		{
			line = gnl_strjoin(line, buffer);
			buffer[0] = 0;
		}
			*(newline_pos + 1) = '\0';
			return (line);
	}
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		line = gnl_strjoin(line, buffer);
		if (read_size < 1)
		{
			buffer[0] = 0;
			return (line);
		}
		if (read_size < BUFFER_SIZE)
			buffer[read_size] = 0;
		newline_pos = ft_strchr(line, '\n');
		if (newline_pos)
		{
			*(newline_pos + 1) = '\0';
			ft_memmove(&buffer[0], &buffer[ft_strlen(line)], BUFFER_SIZE - ft_strlen(line));
			return (line);
		}
	}
	return (NULL);
}

int main()
{
	int fd = open("file.txt", O_RDWR);
	char *line = NULL;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return 0;
}
