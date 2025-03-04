#include "get_next_line.h"

int main() {
	// if (argc != 2)
	// 	exit(1);
	int fd = open("dummy.txt", O_RDONLY);

	char *str = get_next_line(fd);
	// printf("'''" GREEN "%s" RESET "'''\n", str);
	// str = get_next_line(fd);
	// printf("'''" GREEN "%s" RESET "'''\n", str);
	// str = get_next_line(fd);
	// printf("'''" GREEN "%s" RESET "'''\n", str);
	// str = get_next_line(fd);
	// printf("'''" GREEN "%s" RESET "'''\n", str);
	// str = get_next_line(fd);
	// printf("'''" GREEN "%s" RESET "'''\n", str);
	// str = get_next_line(fd);
	// printf("'''" GREEN "%s" RESET "'''\n", str);
	// str = get_next_line(fd);
	// printf("'''" GREEN "%s" RESET "'''\n", str);

	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}

	free(str);
	close(fd);

	return 0;
}