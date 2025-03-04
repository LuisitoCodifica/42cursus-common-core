/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:26:09 by lolit-go          #+#    #+#             */
/*   Updated: 2025/03/04 16:51:03 by lolit-go         ###   ########.fr       */
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
			length += line->newline_index;
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
	// printf("content: " BLUE "''%s''" RESET " -> %ld\n", new_node->content, new_node->length);
	ft_line_addnode(&(*line), new_node);
	if (new_node->newline_index == -1)
		return (-1);
	return (R_SUCCESS);
}

static char	*_buf_join(t_line **line, ssize_t line_len)
{
	char	*str;
	ssize_t	i;
	ssize_t	j;

	// printf(BLUE "length: %ld\n" RESET, line_len);
	if ((*line)->length == 0) {
		// printf(RED "heyyy!" RESET);
		// return (_buf_free(&(*line)), NULL);
		return (_buf_free(&(*line)), NULL);
	}
	str = (char *) malloc((line_len + 2) * sizeof(char));
	if (!str)
		return (_buf_free(&(*line)), NULL);
	j = 0;
	i = 0;
	// while ((*line)->next != NULL)
	while (i < line_len)
	{
		// printf("%.2ld -- ", i);
		str[i] = (*line)->content[j];
		// printf("%ld: %c\n", j, str[i]);
		i++;
		j++;
		if (j >= (*line)->length)
		{
			// printf("length: " BLUE "%ld\n" RESET, (*line)->length);
			// printf("newline: " BLUE "%ld\n" RESET, (*line)->newline_index);
			j = 0;
			ft_line_delnode(&(*line));
		}
	}
	str[i++] = '\n';
	str[i] = 0;
	if ((*line)->newline_index != -1 && (*line)->length > (*line)->newline_index)
		ft_line_addnode(&(*line),
			ft_line_new(ft_strdup((*line)->content + (*line)->newline_index + 1, -1)));
	// ft_line_addnode(&(*line),
	// 	ft_line_new(ft_strdup((*line)->content + (*line)->newline_index + 1, -1)));
	// printf("i: %ld\n", i);
	ft_line_delnode(&(*line));
	return (str);
}

char	*get_next_line(int fd)
{
	static t_line	*line;
	ssize_t			found_nl;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (_buf_free(&line), NULL);
	if (line)
		ft_lstsize(line);
	printf("\n   ---\n\n");
	if (line && line->newline_index != -1)
	{
		// printf(RED "aaa " RESET);
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
	if (line)
		ft_lstsize(line);
	// printf("list size: %d\n",ft_lstsize(line));
	str = _buf_join(&line, _get_line_length(line));
	return (str);
}
