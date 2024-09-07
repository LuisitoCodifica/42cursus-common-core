#include "ft_printf.h"
#include "stdio.h"

int main() {
	// ft_printf(" %c ", 'e');
	// printf("\nchars: %d\n", ft_printf(" %c ", 'e'));
	// printf("\nchars: %d\n", ft_printf(" %s ", "hola"));
	printf("\nchars: %d\n", ft_printf(" %c%c %s !!! ", 'e', 'y', "hola"));
	return 0;
}