/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:29:07 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/12 22:20:19 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline_pos;
	ssize_t		n;

	line = NULL;
	newline_pos = NULL;
	if (buf[0])
	{
		line = ft_strjoin(line, buf);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	while (1)
	{
		buf[n] = '\0';
		newline_pos = ft_strchr(buf, '\n');
		if (newline_pos)
		{
			*(newline_pos + 1) = '\0';
			line = ft_strjoin(line, buf);
			ft_strlcpy(buf, newline_pos + 1, BUFFER_SIZE + 1);
			return (line);
		}
		line = ft_strjoin(line, buf);
		buf[0] = '0';
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buf[n] = '\0';
	}
	if (line && line[0] != '\0')
		return line;
	free (line);
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
