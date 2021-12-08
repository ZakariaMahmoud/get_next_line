/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:02:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/12/08 15:52:10 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	new_line_position(char const *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1)
}

void function(char **backup, int n)
{
	char *line; 

	line = ft_substr(*backup, 0, n);
	free(backup)
}

char	*get_next_line(int fd)
{
	static char *backup;
	char		*buffer;
	char		*line;
	int			rd;
	int			n;

	rd = 1;
	buffer = ft_calloc(1, sizeof(char));
	line = ft_calloc(1, sizeof(char));
	if (!backup)
		backup = ft_calloc(1, sizeof(char));
		
	if (fd == -1 || !buffer || !backup || !line)
		return (0);
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1 || BUFFER_SIZE == 0)
			return (0);
		n = new_line_position(buffer);
		if (n != -1)
		{
			backup = ft_strjoin(backup, buffer);
			
			
		}
		else
			backup = ft_strjoin(backup, buffer);
		
	}
	
	
	
}

int main() 
{ 

 	int	fd;
	int	i;

    fd = open("test.txt", O_RDWR | O_CREAT);
	i = 0;
	while(i++ < 2)
		printf("%s", get_next_line(fd));
}