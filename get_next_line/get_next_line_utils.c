/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:25:03 by lolit-go          #+#    #+#             */
/*   Updated: 2025/02/19 19:45:08 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*ft_line_new(char *content)
{
	t_line	*line;
	ssize_t	length;

	line = (t_line *) malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->content = content;
	length = 0;
	while (line->content[length])
		length++;
	line->length = length;
	line->newline_index = -1;
	length = 0;
	while (line->content[length])
	{
		if (line->content[length] == '\n')
		{
			line->newline_index = length;
			break ;
		}
		length++;
	}
	line->next = NULL;
	return (line);
}

void	ft_line_addnode(t_line **line, t_line *new)
{
	t_line	*last;

	// if (!line || !new)
	// 	return ;
	// if (!(*line))
	// {
	// 	*line = new;
	// 	new->next = new;
	// 	return ;
	// }
	last = *line;
	while (last)
	{
		if (last->next == NULL)
			break ;
		last = last->next;
	}
	if (!last)
		*line = new;
	else
		last->next = new;
	// new->next = *line;
}

void	ft_line_delnode(t_line **line)
{
	t_line	*current;

	if (!line || !(*line))
		return ;
	if ((*line)->next == NULL)
	{
		free((*line)->content);
		free((*line));
		return ;
	}
	current = *line;
	// printf("DELETED NODE: " RED "'''%s'''\n" RESET, current->content);
	free(current->content);
	*line = current->next;
	free(current);
	// printf("CURRENT NODE: " BLUE "'''%s'''\n" RESET, (*line)->content);
	// printf("CURRENT NODE LENGTH: " BLUE "'''%ld'''\n" RESET, (*line)->length);
	// printf("CURRENT NODE NEWLINE: " BLUE "'''%ld'''\n" RESET, (*line)->newline_index);
	// printf("CURRENT NODE NEXT: " BLUE "'''%p'''\n" RESET, (*line)->next);
}

ssize_t	ft_strlcpy(char *dst, const char *src, ssize_t size)
{
	ssize_t	src_len;
	ssize_t	len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	// printf(RED "src length: %ld\n" RESET, src_len);
	if (size == 0)
		return (src_len);
	if (size < 0)
		size = src_len + 1 + ((size + 1) % size);
	len = 0;
	while (src[len] && (len < size - 1))
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s, ssize_t len)
{
	char	*str;
	ssize_t	i;

	if (len == 0)
		return (NULL);
	if (len == -1)
	{
		len = 0;
		while (s[len])
			len++;
	}
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/* temp */

int	ft_lstsize(t_line *lst)
{
	int offset = 0xFFFF;
	int	i = 0;
	while (lst) {
		unsigned long node_addr = (unsigned long long) lst & offset;
		printf(BLUE "%.4lx -> ", node_addr);
		unsigned long next_addr = (unsigned long long) lst->next & offset;
		printf("%.4lx   " RESET, next_addr);
		printf("'''%s'''\n" RESET, lst->content);
		lst = lst->next;
		i++;
	}
	return (i);
}
