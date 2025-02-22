/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:26:09 by lolit-go          #+#    #+#             */
/*   Updated: 2025/02/22 22:42:35 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	_get_line_length(t_line *line)
{
	ssize_t	length;

	length = 0;
	while (line)
	{
		if (line->newline_index == -1)
			length += line->length;
		else
			length += line->newline_index + 1;
		line = line->next;
	}
	return (length);
}

static void	_buf_free(t_line **line)
{
	int	flag;

	if (!line || !(*line))
		return ;
	flag = 1;
	while (flag)
	{
		if ((*line)->next == NULL)
			flag = 0;
		ft_line_delnode(&(*line));
	}
}

static int	_buf_read(t_line **line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	t_line	*new_node;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
		return (R_FAILURE);
	buffer[read_bytes] = 0;
	new_node = ft_line_new(ft_strdup(buffer, -1));
	if (read_bytes == 0)
		new_node->newline_index = new_node->length;
	ft_line_addnode(&(*line), new_node);
	if (new_node->newline_index == -1)
		return (-1);
	return (R_SUCCESS);
}

static char	*_buf_join(t_line **line, ssize_t line_len)
{
	char	*str;
	ssize_t	bytes;
	ssize_t	limit;

	str = (char *) malloc((line_len + 1) * sizeof(char));
	if (!str)
		return (_buf_free(&(*line)), NULL);
	limit = _get_line_length(*line) - 2;
	bytes = 0;
	while (bytes <= limit)
	{
		if ((*line)->newline_index == -1)
			bytes += ft_strlcpy((str + bytes),
					(*line)->content, (*line)->length + 1);
		else
		{
			bytes += ft_strlcpy((str + bytes),
					(*line)->content, (*line)->newline_index + 2);
			ft_line_addnode(&(*line), ft_line_new(ft_strdup(((*line)->content + (*line)->newline_index + 1), -1)));
		}
		ft_line_delnode(&(*line));
	}
	str[bytes + 1] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	static t_line	*line;
	ssize_t			found_nl;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (_buf_free(&line), NULL);
	if (line && line->newline_index != -1)
	{
		str = ft_strdup((line->content + line->newline_index + 1), -1);
		ft_line_addnode(&line, ft_line_new(str));
		str = ft_strdup(line->content, line->newline_index + 1);
		ft_line_delnode(&line);
		return (str);
	}
	found_nl = -1;
	while (found_nl == -1)
	{
		found_nl = _buf_read(&line, fd);
		if (found_nl == 1)
			return (_buf_free(&line), NULL);
	}
	str = _buf_join(&line, _get_line_length(line));
	return (str);
}
