/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:26:09 by lolit-go          #+#    #+#             */
/*   Updated: 2025/02/12 18:37:26 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_buf_join(t_line **line)
{
	char	*result;
	t_line	*first;
	ssize_t	len;

	len = 0;
	first = *line;
	// printf(RED "\n%p\n" RESET, *line); //<--

	printf("\nline content: " RED "'''%s'''" RESET, (*line)->content); //<--
	printf("\nline length: %ld\nnewline index: %ld\n", (*line)->length, (*line)->newline_index); //<--
	if ((*line)->newline_index == -1)
		len += (*line)->length;
	else
		len += (*line)->newline_index;
	(*line) = (*line)->next;
	while (*line != first)
	{
		printf("\nline content: " RED "'''%s'''" RESET, (*line)->content); //<--
		printf("\nline length: %ld\nnewline index: %ld\n", (*line)->length, (*line)->newline_index); //<--
		if ((*line)->newline_index == -1)
			len += (*line)->length;
		else
			len += (*line)->newline_index;
		(*line) = (*line)->next;
	}

	printf("\nresult length: " BLUE "%ld\n" RESET, len); //<--

	// return (result);
	return (NULL);
}

static void	_buf_free(){}

static int	_buf_read(t_line **line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	t_line	*new_node;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
		return (R_FAILURE);
	buffer[read_bytes] = 0;
	new_node = ft_line_new(ft_strdup(buffer));
	ft_line_addnode(&(*line), new_node);
	if (new_node->newline_index == -1)
		return (-1);
	return (R_SUCCESS);
}

char	*get_next_line(int fd)
{
	static t_line	*line;
	ssize_t			found_nl;

	if (fd < 0 || BUFFER_SIZE <= 0) // - [ ] Checkear caso fd sin permiso de lectura
		return (NULL);
	found_nl = -1;
	while (found_nl == -1)
	{
		found_nl = _buf_read(&line, fd);
		if (found_nl == 1)
			return (_buf_free(&line), NULL);
	}
	
	printf("\nlist size: " RED "%d\n" RESET, ft_lstsize(line)); //<--
	
	return (NULL);
	// return (_buf_join(&line));
}
