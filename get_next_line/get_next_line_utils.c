/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:22:37 by lolit-go          #+#    #+#             */
/*   Updated: 2025/01/29 15:46:34 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
		if (s[i] == '\n')
			return (++i);
	}
	return (i);
}

void	*ft_memmove(void *dst, const void *src, int n)
{
	int	i;

	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	while (last)
	{
		if (last->next == NULL)
			break ;
		last = last->next;
	}
	if (!last)
		*lst = new;
	else
		last->next = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*aux;

	next = *lst;
	while (next)
	{
		del(next->content);
		aux = next->next;
		free(next);
		next = aux;
	}
	*lst = NULL;
}

// vvv QUITAR vvv
int		ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
