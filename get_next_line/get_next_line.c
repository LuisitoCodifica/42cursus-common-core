/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:22:47 by lolit-go          #+#    #+#             */
/*   Updated: 2025/01/29 19:01:28 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static int	_buf_free(t_list **lst)
// {
// 	t_list	*next;
// 	t_list	*aux;
// 	size_t	len;

// 	next = *lst;
// 	while (next)
// 	{
// 		free(next->content);
// 		aux = next->next;
// 		free(next);
// 		next = aux;
// 	}
// 	len = ft_strlen(next->content);
// 	if (len < ft_strlen(next->content + len))
// 		return (R_FAILURE);
// 	else
// 	{
// 		*lst = NULL;
// 		return (R_SUCCESS);
// 	}
// }

static int	_buf_check_nl(t_list **lst)
{
	t_list	*last;
	size_t	i;

	last = *lst;
	while (last)
	{
		if (last->next == NULL)
			break ;
		last = last->next;
	}
	i = 0;
	while (((char *) last->content)[i])
	{
		// printf("%c", ((char *) last->content)[i]);
		if (((char *) last->content)[i] == '\n')
			return (R_SUCCESS);
		i++;
	}
	return (i);
}

static char	*_buf_parse(char *buffer)
{
	char	*str;
	ssize_t	len;
	ssize_t	i;

	// printf("buffer: \n" RED "%s" RESET "\n", buffer);
	// for (int i = 0; buffer[i]; i++)
	// 	printf("%c", buffer[i]);
	// printf("\n");

	len = 0;
	while (buffer[len])
	{
		len++;
		// if (buffer[len] == '\n')
		// 	break ;
	}

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);

	i = 0;
	while (i <= len)
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';

	// printf(RED "content: '''%s\n'''" RESET, str);
	return (str);
}

static int	_buf_read(t_list **lst, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*content;
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	// printf("%ld\n", read_bytes);
	if (read_bytes <= 0)
		return (R_FAILURE);
	buffer[read_bytes] = 0;

	content = _buf_parse(buffer);
	if (!content)
		return (R_FAILURE);
	ft_lstadd_back(&(*lst), ft_lstnew(content));
	
	return (R_SUCCESS);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*current;
	char			*line;// = "hola";
	int				nl;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nl = 1;
	while (nl)
	{
		if (_buf_read(&lst, fd))
			return (NULL);
		nl = _buf_check_nl(&lst);
	}

	// Hacer join de las listas
	nl = 0;
	current = lst;
	while (current)
	{
		nl += ft_strlen((char *) current->content);
		current = current->next;
	}
	line = (char *) malloc((nl + 1) * sizeof(char));
	if (!line)
		return (NULL);
	// printf("line malloc: %ld\n", (nl + 1) * sizeof(char));
	nl = 0;
	current = lst;
	while (current)
	{
		ft_memmove((line + nl), (char *) current->content, ft_strlen((char *) current->content));
		// printf(RED "'''%s'''\n" RESET, line);
		nl += ft_strlen((char *) current->content);
		current = current->next;
	}
	line[nl + 1] = 0;

	// Iterar delone y guardar el sobrante
	// if (_buf_free(&lst) && lst && lst->content)
	// {
	// 	char *content = (char *) lst->content;
		
	// 	int len = ft_strlen(content);
	// 	int n_len = ft_strlen(content + len + 1);
	// 	ft_memmove(content, content + len + 1, n_len);
	// 	content[n_len] = '\0';
	// }



	// printf(GREEN "%s\n" RESET, line);
	// printf(BLUE "list size: %d\n\n" RESET, ft_lstsize(lst));

	return (line);
}
