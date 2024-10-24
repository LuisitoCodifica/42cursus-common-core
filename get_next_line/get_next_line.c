/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:04:05 by lolit-go          #+#    #+#             */
/*   Updated: 2024/10/24 18:08:26 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static char		*line;
	static size_t	line_len;
	ssize_t			bytes_read;

	// Detectar si hay sobrante y pasarlo a line

	// Leer fd y pasarlo al buffer
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buffer[bytes_read] = '\0';

	// Calcular line_len
	line_len = ft_get_len(line);

	// Realloc con tamaño de buffer a line
	line = (char *) ft_realloc(line, (line_len * sizeof(char)), ((line_len + bytes_read) * sizeof(char)));
	if (!line)
		return (NULL);

	// Copiar buffer a line
		// Si uno de los carácteres es '\n' retornar line
		// Si se llega al límite del buffer iterar función

	// Si hay sobrante en el buffer ponerlo al principio e iterar función

	return (NULL);
}
