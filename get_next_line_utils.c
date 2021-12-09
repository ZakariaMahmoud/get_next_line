/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:42:42 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/12/09 21:59:29 by zmahmoud         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (0);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

void	*ft_free(char **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
	return (NULL);
}

char	*ft_strjoin(char **s1, char **s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ret;

	if (!*s1 || !*s2)
		return (NULL);
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(*s2);
	ret = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_memcpy(ret, *s1, s1_len);
	ft_memcpy(ret + s1_len, *s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	ft_free(s1);
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


// static char    *ft_copy(char const *s1, char const *s2, char *p)
// {
//     int    i;
//     int    j;

//     i = 0;
//     j = 0;
//     while (s1[i] != '\0')
//     {
//         p[i] = s1[i];
//         i++;
//     }
//     while (s2[j] != '\0')
//     {
//         p[i] = s2[j];
//         j++;
//         i++;
//     }
//     p[i] = '\0';
//     return (p);
// }
// size_t    ft_strlen(const char *str)
// {
//     size_t    i;

//     i = 0;
//     while (str[i] != '\0')
//         i++;
//     return (i);
// }

// char    *ft_strjoin(char  **s1, char  **s2)
// {
//     char    *p;

//     if (!*s1 || !*s2)
//         return (NULL);
    
//     p = malloc((ft_strlen(*s1) + ft_strlen(*s2) + 1) * sizeof(char));
//     if (p == NULL)
//         return (NULL);
//     p = ft_copy(*s1, *s2, p);
//     ft_free(s1);
//     return (p);
// }


// char    *ft_substr(char const *s, unsigned int start, size_t len)
// {
//     char    *p;
//     size_t    i;

//     i = 0;
//     if (!s)
//         return (NULL);
//     // if (len >= ft_strlen(s))
//     //     len = ft_strlen(s);
//     p = malloc((len + 1) * sizeof(char));
//     if (p == NULL)
//         return (NULL);
//     if (start <= ft_strlen(s))
//     {
//         while (i < len && s)
//         {
//             p[i] = s[start];
//             i++;
//             start++;
//         }
//     }
//     p[i] = '\0';
//     return (p);
// }

// void    *ft_calloc(size_t count, size_t size)
// {
//     char    *p;
//     size_t    total;
//     size_t    i;

//     i = 0;
//     total = count * size;
//     p = malloc(total);
//     if (p == NULL)
//     {
//         return (NULL);
//     }
//     while (i < total)
//     {
//         p[i] = 0;
//         i++;
//     }
//     return (p);
// }