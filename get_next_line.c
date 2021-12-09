/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:02:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/12/09 23:24:49 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int	new_line_position(char const *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (i == 0)
		return (-2);
	return (-1);
}

char	*ft_ret(char **rest)
{
	char	*line;
	char	*tmp;
	int		n;
	
	if (!*rest || **rest == '\0')
		return (ft_free(rest));	
	n = new_line_position(*rest);
	if (n > -1)
	{
		line =  ft_substr(*rest, 0, n + 1);
		tmp = ft_substr(*rest, n + 1, ft_strlen(*rest + n + 1));
		ft_free(rest);
		*rest = tmp;
		return (line);
	}
	else
	{
		line = ft_substr(*rest, 0, ft_strlen(*rest));
		ft_free(rest);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char *rest;
	char		*buffer;
	int			rd;
	int			n;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || !buffer)
		return (ft_free(&buffer));
	if (!rest)
	{
		rest = (char *)malloc(1 * sizeof(char));
		if (!rest)
			return (NULL);
		rest[0] = '\0';
	}
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{
			ft_free(&buffer);
			return (ft_free(&rest));			
		}
		buffer[rd] = '\0';
		n = new_line_position(buffer);
		if (n > -1)
		{
			rest = ft_strjoin(&rest, &buffer);
			break;
		}
		else if (n == -2)
			break;
		rest = ft_strjoin(&rest, &buffer);
	}
	ft_free(&buffer);
	return (ft_ret(&rest));
}

