/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:29:07 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/13 21:44:40 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		read_size;
	char		*newline_pos;

	line = NULL;
	if (buffer[0])
	{
		line = gnl_strjoin(line, buffer);
		*buffer = '\0';
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	line = gnl_strjoin(line, buffer);
	buffer[read_size] = '\0';
	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
	{
		printf("this is the buffer : %s\n", buffer);
		*(newline_pos + 1) = '\0';
		printf("this is the buffer : %s\n", buffer);
		return (line);
	}
	return (NULL);
}

int main()
{
	int fd = open("file.txt", O_RDWR);
	char *line = NULL;
	line = get_next_line(fd);
	printf("line returned : %s", line);
	line = get_next_line(fd);
	printf("line returned : %s", line);
	return 0;
}
