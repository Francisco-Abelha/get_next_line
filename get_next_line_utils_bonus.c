/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:23:09 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/19 13:57:27 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			break ;
	}
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*ret;
	char	*start;
	char	*temp;

	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (free(s1), NULL);
	start = ret;
	temp = s1;
	while (temp && *temp)
		*ret++ = *temp++;
	temp = s2;
	while (*temp)
	{
		*ret++ = *temp;
		if (*temp == '\n')
		{
			temp++;
			break ;
		}
		temp++;
	}
	*ret = '\0';
	free(s1);
	return (start);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	move_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

char	*join_move(char *line, char *buffer)
{
	line = gnl_strjoin(line, buffer);
	move_buffer(buffer);
	return (line);
}
