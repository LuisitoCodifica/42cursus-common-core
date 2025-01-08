#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
		return (NULL);
	buffer[read_bytes] = 0;

	return (buffer);
}
