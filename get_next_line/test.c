#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *read_line(int fd) {
	static char buffer[BUFFER_SIZE + 1];
	ssize_t bytes_read;
	char *line;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return NULL;
	buffer[bytes_read] = '\0';

	line = (char *) malloc((bytes_read + 1) * sizeof(char));
	if (!line)
		return NULL;

	memcpy(line, buffer, bytes_read);
	line[bytes_read] = '\0';

	printf("%s", line);

	return line;
}

int main(int argc, char **argv) {
	if (argc < 3)
		return 1;

	int fd = open(argv[1], O_RDONLY);
	int i = argv[2][0] - '0';

	while (i) {
		read_line(fd);
		sleep(1);
		i--;
	}

	close(fd);

	return 0;
}