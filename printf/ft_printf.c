/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:53:22 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/09 17:42:18 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		num_chars;
	va_list	params;

	num_chars = 0;
	va_start(params, s);
	// write(0, "\"", 1);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
				num_chars += ft_putchar(va_arg(params, int));
			else if (*s == 's')
				num_chars += ft_putstr(va_arg(params, char *));
			// else if (*s == 'p')
			// else if (*s == 'd')
			// else if (*s == 'i')
			// else if (*s == 'u')
			// else if (*s == 'x')
			// else if (*s == 'X')
			else if (*s == '%')
				num_chars += ft_putchar('%');
		}
		else
			num_chars += ft_putchar(*s);
		s++;
	}
	va_end(params);
	// write(0, "\"", 1);
	return (num_chars);
}
