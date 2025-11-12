#ifndef BUFFER_SIZE
# define BUFFER_SIZE -1
#endif

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

char *ft_strjoin(char *line, char *buf)
{
	char *new;
	int line_l = 0;
	int buf_l = 0;

	if (line)
		line_l = strlen(line);
	buf_l = strlen(buf);
	new = realloc(line, line_l + buf_l + 1);
	memmove(new + line_l, buf, BUFFER_SIZE);
	buf[0] = 0;
	return (new);
}

char *gnl(int fd)
{
	int read_size;
	static char buffer[BUFFER_SIZE + 1];
	char *line = NULL;
	if (buffer[0])
	{
		line = ft_strjoin(line, buffer);
		if (strchr(line, '\n'))
			return (line);
	}
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 1)
			return (line);
		if (read_size < BUFFER_SIZE)
			buffer[read_size] = 0;
		line = ft_strjoin(line, buffer);
		if (strchr(line, '\n'))
			return (line);
	}
}

/* int main()
{
	int fd = open("main.c", O_RDWR);
	char *line = NULL;
	int linhas = 1000;
	while ((line = gnl(fd)) && linhas--)
	{
		printf("%s", line);
		free(line);
	}
	return 0;
} */
