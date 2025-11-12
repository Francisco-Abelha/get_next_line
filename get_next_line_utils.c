/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:36:40 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/12 21:12:58 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i ++;
		s++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;

	dest_len = ft_strlen(dst);
	i = 0;
	if (size <= dest_len)
		return (size + ft_strlen(src));
	while (src[i] && (i + dest_len < size - 1))
	{
		dst[i + dest_len] = src[i];
		i++;
	}
	dst[i + dest_len] = '\0';
	return (dest_len + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	ret;

	len = size;
	ret = ft_strlen(src);
	if (size > 0)
	{
		while (*src && len - 1 > 0)
		{
			*dst = *src;
			len--;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	total_len;

	if (!s2)
		return ((char *)s1);
	if (!s1)
		return (ft_strdup(s2));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(total_len + 1);
	if (!ret)
	{
		free ((char *)s1);
		return (NULL);
	}
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, s2, total_len + 1);
	return (ret);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > (__SIZE_MAX__ / size))
		return (malloc(1));
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, size * nmemb);
	return (array);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
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

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	ret = malloc(len * sizeof(char) + 1);
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
