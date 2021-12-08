#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
# include <stdarg.h> 
#include <unistd.h>
#include <stdio.h>


size_t	ft_strlen(const char *s);
void	*ft_free(int count, ...);
void	ft_bzero(void *str, size_t n);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif