#include "get_next_line.h"

int main(int argc, char **argv) {
	if (argc < 2)
		return 1;

	int fd = open(argv[1], O_RDONLY);
	// int i = argv[2][0] - '0';

	// while (i) {
	// 	get_next_line(fd);
	// 	sleep(1);
	// 	i--;
	// }

	printf("\n---\n\n");

	get_next_line(fd);
	get_next_line(fd);

	close(fd);

	return 0;
}