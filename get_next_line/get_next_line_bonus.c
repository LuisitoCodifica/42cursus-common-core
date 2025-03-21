/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:44:40 by lolit-go          #+#    #+#             */
/*   Updated: 2025/03/21 20:14:53 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int
	_line_push(char **line, size_t i)
{
	char	*aux;
	size_t	rem_length;

	if (i > 0)
		rem_length = ft_strlen(*line + i);
	else
		return (0);
	if (rem_length <= 0)
		return (_line_free(&(*line)), 0);
	aux = (char *) malloc(sizeof(char) * (rem_length + 1));
	if (!aux)
		return (1);
	ft_strlcpy(aux, *line + i, rem_length + 1);
	free(*line);
	*line = aux;
	return (0);
}

static char
	*_line_slice(char **line, ssize_t nl_index)
{
	char	*result;
	size_t	i;

	if (nl_index == EOF && !(*line))
		return (_line_free(&(*line)), NULL);
	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	result = (char *) malloc(sizeof(char) * (i + 1));
	if (!result)
		return (_line_free(&(*line)), NULL);
	ft_strlcpy(result, *line, i + 1);
	if (_line_push(&(*line), i))
		return (_line_free(&(*line)), NULL);
	if (nl_index == EOF)
		_line_free(&(*line));
	return (result);
}

static int
	_line_join(char **dst, const char *src)
{
	char	*result;
	size_t	dst_len;
	size_t	src_len;

	if (!(*dst))
		dst_len = 0;
	else
		dst_len = ft_strlen(*dst);
	src_len = ft_strlen(src);
	result = (char *) malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!result)
		return (1);
	if (*dst)
		ft_strlcpy(result, *dst, dst_len + 1);
	ft_strlcpy((result + dst_len), src, src_len + 1);
	if (*dst)
		free(*dst);
	*dst = result;
	return (0);
}

static ssize_t
	_buf_read(char **line, int fd)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (R_FAILED);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
		return (free(buffer), R_FAILED);
	if (read_bytes == 0)
		return (free(buffer), EOF);
	buffer[read_bytes] = 0;
	if (_line_join(&(*line), buffer))
		return (free(buffer), R_FAILED);
	if (ft_strchr(*line, '\n'))
		return (free(buffer), 1);
	else
		return (free(buffer), NEWLINE_NOT_FOUND);
}

char
	*get_next_line(int fd)
{
	static char	*line[1024];
	ssize_t		nl_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nl_index = NEWLINE_NOT_FOUND;
	if (line[fd] && ft_strchr(line[fd], '\n'))
		return (_line_slice(&line[fd], nl_index));
	while (nl_index == NEWLINE_NOT_FOUND)
	{
		nl_index = _buf_read(&line[fd], fd);
		if (nl_index == R_FAILED)
			return (_line_free(&line[fd]), NULL);
	}
	return (_line_slice(&line[fd], nl_index));
}
