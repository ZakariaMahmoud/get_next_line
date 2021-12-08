/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:42:42 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/12/07 22:42:11 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void *ft_free(int count, ...)
{
	va_list args;
	int		i;

	va_start(args, count);
	i = 0;	
	while (i < count)
	{
		free(va_arg(args, void *));
		i++;
	}
	va_end(args);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_memcpy(ret, s1, s1_len);
	ft_memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	
	return (ret);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!s && !d)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}	
	return (dest);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = str;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;

	ptr = (void *)malloc (count * size);
	if (!ptr)
		return (0);
	i = 0;
	ft_bzero(ptr, count * size);
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}