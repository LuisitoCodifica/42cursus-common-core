#include "get_next_line.h"

int main(int argc, char **argv) {
	if (argc < 3)
		return 1;

	int fd = open(argv[1], O_RDONLY);
	char *str;
	// int i = argv[2][0] - '0';

	// while (i) {
	// 	get_next_line(fd);
	// 	sleep(1);
	// 	i--;
	// }

	// printf("\n---\n\n");

	int i = 0;
	int n = argv[2][0] - '0';
	while (i < n)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		i++;
	}

	free(str);
	close(fd);

	return 0;
}