/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:04:05 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/22 16:11:16 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buffer[bytes_read] = '\0';
	printf("1.\n ///%s///\n\n", buffer);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buffer[bytes_read] = '\0';
	printf("2.\n ///%s///\n\n---\n\n", buffer);
	line = (char *) malloc((bytes_read + 1) * sizeof(char));
	if (!line)
		return (NULL);
	memcpy(line, buffer, bytes_read);
	line[bytes_read] = '\0';
	// printf("%s", line);
	return (line);
}
