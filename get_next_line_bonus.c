/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:22:04 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/12/11 03:33:15 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	new_line_position(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
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
		line = ft_substr(*rest, 0, n + 1);
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

int	small_code(int fd, char **buffer, char **rest)
{
	int	rd;
	int	n;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, *buffer, BUFFER_SIZE);
		if (rd < 0)
		{
			ft_free(buffer);
			ft_free(rest);
			return (0);
		}
		*(*buffer + rd) = '\0';
		n = new_line_position(*buffer);
		if (n > -1)
		{
			*rest = ft_strjoin(rest, buffer);
			break ;
		}
		else if (n == -2)
			break ;
		*rest = ft_strjoin(rest, buffer);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	if (!rest[fd])
	{
		rest[fd] = (char *)malloc(1 * sizeof(char));
		if (!rest[fd])
			return (NULL);
		rest[fd][0] = '\0';
	}
	if (!small_code(fd, &buffer, &rest[fd]))
		return (0);
	ft_free(&buffer);
	return (ft_ret(&rest[fd]));
}
