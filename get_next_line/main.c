#include "get_next_line.h"

int main(int argc, char **argv) {
	if (argc < 3)
		return 1;

	int fd = open(argv[1], O_RDONLY);
	int i = argv[2][0] - '0';

	while (i) {
		get_next_line(fd);
		sleep(1);
		i--;
	}

	close(fd);

	return 0;
}