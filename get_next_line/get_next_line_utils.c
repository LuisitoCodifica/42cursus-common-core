/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:25:03 by lolit-go          #+#    #+#             */
/*   Updated: 2025/02/12 18:51:58 by lolit-go         ###   ########.fr       */
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
	t_line	*temp;
	t_line	*prev;

	if (!line || !(*line)) // Verifica si la lista está vacía
		return ;

	temp = *line;

	// Si solo hay un nodo en la lista
	if (temp->next == temp)
	{
		free(temp);
		*line = NULL;
		return ;
	}

	// Encuentra el nodo anterior al nodo que se va a eliminar
	prev = temp;
	while (prev->next != *line)
		prev = prev->next;

	// Ajusta el puntero del nodo anterior para omitir el nodo actual
	prev->next = temp->next;
	*line = temp->next; // Mueve el puntero de la lista al siguiente nodo

	free(temp);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
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
