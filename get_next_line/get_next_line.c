/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:22:47 by lolit-go          #+#    #+#             */
/*   Updated: 2025/01/18 20:54:11 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_buf_parse(char *buffer, ssize_t read_bytes)
{
	char	*aux;
	ssize_t	i;

	// printf("buffer:\n%s\n", buffer);
	for (int i = 0; buffer[i]; i++)
		printf("%c", buffer[i]);

	aux = malloc((read_bytes + 1) * sizeof(char));
	if (!aux)
		return (NULL);

	i = 0;
	while (i < read_bytes)
	{
		aux[i] = buffer[i];
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	aux[i] = '\0';

	return (aux);
}

static int	_buf_read(t_list **lst, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*content;
	ssize_t	read_bytes;
	
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
		return (R_FAILURE);
	buffer[read_bytes] = 0;

	content = _buf_parse(buffer, read_bytes);
	if (!content)
		return (R_FAILURE);
	ft_lstadd_back(&(*lst), ft_lstnew(content));

	return (R_SUCCESS);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line = "hola";

	// if (_buf_read(&lst, fd))
	// 	return (NULL);

	_buf_read(&lst, fd);
		printf("\n");

	if (lst && lst->content) {
		for (int i = 0; ((char *) lst->content)[i] != '\0'; i++) {
			printf("%c", ((char *) lst->content)[i]);
		}
		printf("\n\n");
	}

	_buf_read(&lst, fd);
		printf("\n");

	if (lst && lst->content) {
		lst = lst->next;
		for (int i = 0; ((char *) lst->content)[i] != '\0'; i++) {
			printf("%c", ((char *) lst->content)[i]);
		}
		printf("\n\n");
	}

	_buf_read(&lst, fd);
		printf("\n");

	if (lst && lst->content) {
		lst = lst->next;
		for (int i = 0; ((char *) lst->content)[i] != '\0'; i++) {
			printf("%c", ((char *) lst->content)[i]);
		}
		printf("\n\n");
	}


	return (line);
}
