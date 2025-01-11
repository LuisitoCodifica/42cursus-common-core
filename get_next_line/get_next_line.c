/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:22:47 by lolit-go          #+#    #+#             */
/*   Updated: 2025/01/11 21:10:01 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
		return (NULL);
	buffer[read_bytes] = 0;

	printf("buffer:\n" RED "\"\"\"%s\"\"\"\n" RESET, buffer);
	printf("\n");
	
	printf("buffer length: %d\n", ft_strlen(buffer));
	printf("\n");

	char *buf_rem = ft_memchr(buffer, '\n', read_bytes) + 1;
	size_t nl_index = buf_rem - buffer - 1;
	printf("new_line index: %lu\n", nl_index);
	printf("\n");

	line = (char *) malloc(nl_index * sizeof(char));
	if (!line)
		return (NULL);

	ft_memcpy(line, buffer, nl_index);
	line[nl_index] = 0;

	printf("buffer remainder:\n" BLUE "\"\"\"%s\"\"\"\n" RESET, buf_rem);
	printf("\n");

	unsigned int len = ft_strlen(buf_rem);
	ft_memmove(buffer, buf_rem, len);
	buffer[len] = 0;

	printf("buffer after memmove:\n" RED "\"\"\"%s\"\"\"\n" RESET, buffer);
	printf("\n");

	return (line);
}
