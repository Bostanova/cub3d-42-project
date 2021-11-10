/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:49:36 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 14:20:57 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fill_buf(int fd, char **buf)
{
	char	*buffer;
	char	*old_buf;
	int		reader;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buffer))
		return (-1);
	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader == -1)
	{
		free(buffer);
		return (-1);
	}
	buffer[reader] = '\0';
	old_buf = *buf;
	*buf = ft_strjoin(*buf, buffer);
	if (!*buf)
		return (-1);
	free(old_buf);
	free(buffer);
	return (reader);
}

static int	check_result(int counter, char **buf, char **line)
{
	if (counter == -1)
	{
		free(*buf);
		*buf = 0;
		return (-1);
	}
	if (counter == 0)
	{
		*line = ft_strjoin(*buf, 0);
		if (!*line)
		{
			return (-1);
		}
		free(*buf);
		*buf = 0;
		return (0);
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*is_nl;
	static char	*buf;
	int			reader;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	is_nl = ft_strchr(buf, '\n');
	while (!(is_nl))
	{
		reader = fill_buf(fd, &buf);
		if (reader <= 0)
		{
			return (check_result(reader, &buf, line));
		}
		is_nl = ft_strchr(buf, '\n');
	}
	*is_nl = '\0';
	is_nl++;
	*line = ft_strjoin(0, buf);
	if (!*line)
	{
		return (-1);
	}
	ft_strlcpy(buf, is_nl, ft_strlen(is_nl) + 1);
	return (1);
}
