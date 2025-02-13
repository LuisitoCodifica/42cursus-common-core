#include "get_next_line.h"

int main(int argc, char **argv) {
	if (argc != 2)
		exit(1);
	int fd = open(argv[1], O_RDONLY);

	char *str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}

	close(fd);

	return 0;
}