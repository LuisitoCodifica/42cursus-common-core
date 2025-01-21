/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:22:47 by lolit-go          #+#    #+#             */
/*   Updated: 2025/01/21 18:17:14 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static int	_buf_free(){}

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
		printf("%c", ((char *) last->content)[i]);
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
	char			*line = "hola";
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

	printf(BLUE "list size: %d\n\n" RESET, ft_lstsize(lst));

	return (line);
}
