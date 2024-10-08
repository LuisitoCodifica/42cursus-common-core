/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:04:05 by lolit-go          #+#    #+#             */
/*   Updated: 2024/10/06 19:07:43 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	static size_t		line_len;
	size_t		buffer_len;
	ssize_t		bytes_read;

	size_t		iter = 0; // <--

	line = NULL;
	while (1)
	{
		printf("iter %ld\n-----\n", iter++); // <--
		
		if (line_len > 0)
		{
			line = (char *) ft_realloc(line, 0, (line_len * sizeof(char)));
			if (!line)
				return (NULL);
			ft_memcpy(line, buffer, line_len);
		}

		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		printf("\nbuffer: %s\n", buffer); // <--

		line_len = ft_get_len(line);
		printf("line_len: %ld\n", line_len); // <--
		buffer_len = ft_get_len(buffer);
		printf("buffer_len: %ld\n", buffer_len); // <--

		line = (char *) ft_realloc(line, (line_len * sizeof(char)), ((line_len + buffer_len) * sizeof(char)));
		printf("size: %ld\n", (line_len * sizeof(char))); // <--
		printf("new_size: %ld\n", ((line_len + buffer_len) * sizeof(char))); // <--
		if (!line)
			return (NULL);

		// if (line_len > 0)
		// 	ft_memcpy(line, buffer, line_len);
		// printf(BLUE "\n%s\n" RESET, line);

		size_t i = 0;
		// printf("\"%ld\"\n", ft_strlen(line));
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				line[i] = '\0';
				printf(GREEN "\n\"%s\" -> len: %ld\n" RESET, line, ft_get_len(line));
				printf(RED "\nleftover: \"%s\" -> len: %ld\n\n" RESET, (buffer + i + 1), ft_get_len(buffer + i + 1)); // <--
				if (buffer_len > line_len)
				{
					line_len = ft_get_len(buffer + i + 1);
					ft_memcpy(buffer, (buffer + i + 1), line_len);
					buffer[line_len] = 0;
				}
				else
					line_len = 0;
				return (line);
			}
			// printf("%c -- ", buffer[i]);
			if (line_len > 0)
				line[i + line_len] = buffer[i];
			else
				line[i] = buffer[i];
			// printf("%c\n", line[i]);
			i++;
		}
	}
	
	return (NULL);
}
