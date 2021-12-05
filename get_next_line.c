/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:02:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/12/05 19:01:26 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program to illustrate 
// read system Call 

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

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


char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buffer;
	char		*p1;
	char		*p2;
	int			i;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		str = (char *)ft_calloc(1, sizeof(char));
	if (fd == -1 || !buffer || !str)
		return (ft_free(2, buffer, str));
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0')
	{
		if(buffer[i] == '\n')
		{
			p1 = ft_substr(buffer, 0, i + 1);
			p2 = ft_strjoin(str, p1);
			printf("\np2 = |%s|", p2);
			ft_free(2, p1, str);
			str = ft_substr(&buffer[i + 1], 0, ft_strlen(&buffer[i + 1]));
			return (p2);
		}
		i++;
	}
	
	str = ft_strjoin(str, buffer);
	return str;
}


int main() 
{ 

 	int fd;
    // int i = 0;
    // char *c = (char *) calloc(100, sizeof(char));
	// printf("buffer = |%s|\n", buffer);
    fd = open("test.txt", O_RDWR | O_CREAT);

	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);get_next_line(fd);
	

}