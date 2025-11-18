/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:29:27 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/18 19:48:28 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);

//utils
size_t	ft_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	move_buffer(char *buffer);
char	*join_move(char *line, char *buffer);
#endif
