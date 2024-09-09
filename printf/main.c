#include "ft_printf.h"
#include "stdio.h"

int main() {
	int x = 42;
	int *px = &x;
	// ft_printf(" %c ", 'e');
	// printf("\nchars: %d\n", ft_printf(" %c ", 'e'));
	// printf("\nchars: %d\n", ft_printf(" %s !!! ", "hola"));
	// printf("\nchars: %d\n", ft_printf(" %% %c%c %s !!! ", 'e', 'y', "hola"));
	printf("%X\n", x);
	return 0;
}