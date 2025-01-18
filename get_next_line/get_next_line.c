/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:22:47 by lolit-go          #+#    #+#             */
/*   Updated: 2025/01/18 21:12:54 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_buf_parse(char *buffer)
{
	char	*str;
	ssize_t	len;
	ssize_t	i;

	// printf("buffer:\n%s\n", buffer);
	for (int i = 0; buffer[i]; i++)
		printf("%c", buffer[i]);

	len = 0;
	while (buffer[len])
	{
		len++;
		if (buffer[len] == '\n')
			break ;
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

	return (str);
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

	content = _buf_parse(buffer);
	if (!content)
		return (R_FAILURE);
	ft_lstadd_back(&(*lst), ft_lstnew(content));

	return (R_SUCCESS);
}

static void __print_lst(t_list *lst, int fd)
{
	_buf_read(&lst, fd);
		printf(RED "\n\nres: " RESET);

	if (lst && lst->content) {
		for (int i = 0; ((char *) lst->content)[i] != '\0'; i++) {
			printf("%c", ((char *) lst->content)[i]);
		}
		printf("\n\n");
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line = "hola";

	// if (_buf_read(&lst, fd))
	// 	return (NULL);

	__print_lst(lst, fd);
	__print_lst(lst, fd);
	__print_lst(lst, fd);
	

	return (line);
}
