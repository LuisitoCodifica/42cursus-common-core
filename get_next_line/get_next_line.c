/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:26:09 by lolit-go          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:10 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	_calc_result_len(t_line *line)
{
	t_line	*first;
	ssize_t	len;

	len = 0;
	first = line;
	while (line)
	{
		// printf("\nline content: " RED "'''%s'''" RESET, line->content); //<--
		// printf("\nline length: %ld\nnewline index: %ld\n", line->length, line->newline_index); //<--
		if (line->newline_index == -1)
			len += line->length;
		else
			len += line->newline_index;
		line = line->next;
	}
	// printf("\nresult length: " BLUE "%ld\n\n" RESET, len + 1); //<--
	return (len + 1);
}

static char	*_buf_join(t_line **line)
{
	char	*result;
	ssize_t	len;
	ssize_t	i;

	len = _calc_result_len(*line);
	result = (char *) malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (*line)
	{
		if ((*line)->newline_index == -1)
		{
			ft_strlcpy((result + i), (*line)->content, (*line)->length + 1);
			i += (*line)->length;
		}
		else
		{
			ft_strlcpy((result + i), (*line)->content, (*line)->newline_index + 2);
			ft_line_addnode(&(*line), ft_line_new(ft_strdup((*line)->content + (*line)->newline_index + 1, -1)));
			*line = (*line)->next;
			break ;
		}
		*line = (*line)->next;
	}
	result[len + 1] = 0;

	// printf("remainder: " BLUE "'''%s'''\n\n" RESET, (*line)->content);

	// printf(GREEN "'''%s'''\n" RESET, result);

	return (result);
	// return (NULL);
}

static void	_buf_free(t_line **line)
{
	int	flag;

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
	if (read_bytes <= 0)
		return (R_FAILURE);
	buffer[read_bytes] = 0;
	new_node = ft_line_new(ft_strdup(buffer, -1));
	ft_line_addnode(&(*line), new_node);
	if (new_node->newline_index == -1)
		return (-1);
	return (R_SUCCESS);
}

char	*get_next_line(int fd)
{
	static t_line	*line;
	ssize_t			found_nl;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0) // - [ ] Checkear caso fd sin permiso de lectura
		return (_buf_free(&line), NULL);
	if (line && line->newline_index != -1)
	{
		// printf(RED ">>> pling! <<<\n" RESET);
		// printf("%s\n", line->content);
		// printf("%ld\n", line->newline_index);
		ft_line_addnode(&line, ft_line_new(ft_strdup((line->content + line->newline_index + 1), -1)));
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
	
	// printf("\n");
	// printf("\nlist size: " RED "%d\n" RESET, ft_lstsize(line)); //<--
	
	// return (NULL);
	return (_buf_join(&line));
}
