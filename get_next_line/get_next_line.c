/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:04:05 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/24 19:09:48 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			line_len;
	ssize_t		bytes_read;
	size_t		i;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buffer[bytes_read] = '\0';

	line_len = ft_get_line_len(fd);
	
	line = (char *) malloc((line_len + 1) * sizeof(char));
	if (!line)
		return (NULL);

	i = 0;
	while (buffer[i] != '\n')
	{
		while (buffer[i] || buffer[i] != '\n')
		{
			
		}
	}
	line[line_len] = '\0';
	// printf("%s", line);
	
	return (line);
}
