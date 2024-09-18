#include "ft_printf.h"
#include "stdio.h"
#include "limits.h"

unsigned int er(unsigned int n)
{
	return (UINT_MAX + n + 1);
}

int main() {
	// int x = 42;
	// int *px = &x;
	// ft_printf("\" %c \"\n", 'e');
	// ft_printf("\" %s !!! \"\n", "hola");
	// ft_printf("\" %% %c%c %s !!! \"\n", 'e', 'y', "hola");
	// ft_printf("\" %x %X \"\n", 1100, 1100);
	// ft_printf("\" %d -- (%d)  -- %d \"\n", 286354, -1876763, 0);
	// ft_printf("\" %i -- (%i)  -- %i \"\n", 286354, -1876763, 0);
	// ft_printf("\"\t%s\"\n\n", "holi");

	// printf("va: %p\n", px);
	// ft_printf("ft: %p\n\n", px);

	// printf("va: %u\n", 4294967295U);		// 4294967295
	// ft_printf("ft: %u\n", 4294967295U);		// 0xffffffff

	// printf("\n\"%-4d\"\n\n", 3030);

	// printf("chars: %d\n\n", printf("ey %wd holaaa", 33));

	// printf("\nchars: %d\n\n", ft_printf("ey %wc holaaa", 33));

	// printf("%d\n", ft_printf("%s\n", "eyeyey"));

	// printf("NULL %s NULL\n", NULL);

	// ft_printf("%X\n", 9223372036854775807LL);

	ft_printf("ft: %p\n",	 0);
	printf("va: %p\n",		 0);

	return 0;
}