/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:22:47 by lolit-go          #+#    #+#             */
/*   Updated: 2025/01/13 20:11:44 by lolit-go         ###   ########.fr       */
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


	// Busca el salto de línea
	char *buf_rem = ft_memchr(buffer, '\n', read_bytes) + 1;
	size_t nl_index = buf_rem - buffer - 1;
	printf("new_line index: %lu\n", nl_index);
	printf("\n");

	// Reserva la memoria para `line`
	line = (char *) malloc(nl_index * sizeof(char));
	if (!line)
		return (NULL);

	// Copia la línea desde el buffer a `line`
	ft_memcpy(line, buffer, nl_index);
	line[nl_index] = 0;

	printf("buffer remainder:\n" BLUE "\"\"\"%s\"\"\"\n" RESET, buf_rem);
	printf("\n");

	// Mueve el sobrante al principio del buffer
	unsigned int len = ft_strlen(buf_rem);
	ft_memmove(buffer, buf_rem, len);
	buffer[len] = 0;

	printf("buffer after memmove:\n" RED "\"\"\"%s\"\"\"\n" RESET, buffer);
	printf("\n");

	printf(GREEN "\"\"\"%s\"\"\"\n" RESET, line);


	// ---
	printf("\n\n");
	free(line);
	// ---


	// Reserva la memoria para `line`
	line = (char *) malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (!line)
		return (NULL);

	// Copia el sobrante a una variable auxiliar
	char *aux = (char *) malloc((ft_strlen(buffer) + 1) * sizeof(char));
	ft_memcpy(aux, buffer, ft_strlen(buffer));
	line[ft_strlen(buffer) + 1] = 0;

	// Lee de nuevo el buffer
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
		return (NULL);
	buffer[read_bytes] = 0;

	printf("buffer:\n" RED "\"\"\"%s\"\"\"\n" RESET, buffer);
	printf("\n");
	
	printf("buffer length: %d\n", ft_strlen(buffer));
	printf("\n");

	// Busca el salto de línea
	buf_rem = ft_memchr(buffer, '\n', read_bytes) + 1;
	nl_index = buf_rem - buffer - 1;
	printf("new_line index: %lu\n", nl_index);
	printf("\n");

	printf("buffer remainder:\n" BLUE "\"\"\"%s\"\"\"\n" RESET, buf_rem);
	printf("\n");

	// Hace la reserva completa para `line`
	line = (char *) malloc((ft_strlen(line) + nl_index + 1) * sizeof(char));
	if (!line)
		return (NULL);

	// Copia `aux` y el buffer a línea para componer la línea completa
	ft_memcpy(line, aux, ft_strlen(aux));
	ft_memcpy((line + ft_strlen(aux)), buffer, nl_index);
	line[ft_strlen(aux) + nl_index] = 0;

	// Mueve el sobrante al principio del buffer
	len = ft_strlen(buf_rem);
	ft_memmove(buffer, buf_rem, len);
	buffer[len] = 0;

	printf("buffer after memmove:\n" RED "\"\"\"%s\"\"\"\n" RESET, buffer);
	printf("\n");

	printf(GREEN "\"\"\"%s\"\"\"\n" RESET, line);


	// ---
	printf("\n\n");
	free(line);
	free(aux);
	// ---


	// Reserva la memoria para `line`
	line = (char *) malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (!line)
		return (NULL);

	// Copia el sobrante a una variable auxiliar
	aux = (char *) malloc((ft_strlen(buffer) + 1) * sizeof(char));
	ft_memcpy(aux, buffer, ft_strlen(buffer));
	line[ft_strlen(buffer) + 1] = 0; // <-- Cambiar por `aux` (?)

	// Lee de nuevo el buffer
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
		return (NULL);
	buffer[read_bytes] = 0;

	printf("buffer:\n" RED "\"\"\"%s\"\"\"\n" RESET, buffer);
	printf("\n");
	
	printf("buffer length: %d\n", ft_strlen(buffer));
	printf("\n");

	// Busca el salto de línea
	buf_rem = ft_memchr(buffer, '\n', read_bytes) + 1;
	nl_index = buf_rem - buffer - 1;
	printf("new_line index: %lu\n", nl_index);
	printf("\n");

	printf("buffer remainder:\n" BLUE "\"\"\"%s\"\"\"\n" RESET, buf_rem);
	printf("\n");

	// Hace la reserva completa para `line`
	printf("line: %s\n\n", line);

	line = (char *) malloc((ft_strlen(line) + nl_index + 1) * sizeof(char));
	printf("allocation length: %d + %ld + 1 = %ld\n\n", ft_strlen(line), nl_index, (ft_strlen(line) + nl_index + 1));
	if (!line)
		return (NULL);

	// Copia `aux` y el buffer a línea para componer la línea completa
	ft_memcpy(line, aux, ft_strlen(aux));
	ft_memcpy((line + ft_strlen(aux)), buffer, nl_index);
	line[ft_strlen(aux) + nl_index] = 0;

	// Mueve el sobrante al principio del buffer
	len = ft_strlen(buf_rem);
	ft_memmove(buffer, buf_rem, len);
	buffer[len] = 0;

	printf("buffer after memmove:\n" RED "\"\"\"%s\"\"\"\n" RESET, buffer);
	printf("\n");

	printf(GREEN "\"\"\"%s\"\"\"\n" RESET, line);

	return (line);
}
