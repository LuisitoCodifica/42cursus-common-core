/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:53:22 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/12 00:13:50 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		num_chars;
	va_list	params;

	num_chars = 0;
	va_start(params, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
				num_chars += ft_putchar(va_arg(params, int));
			else if (*s == 's')
				num_chars += ft_putstr(va_arg(params, char *));
			else if (*s == 'p')
				num_chars += ft_putstr(ft_mem_addr(va_arg(params, void *)));
			else if (*s == 'd')
				num_chars += ft_putstr(ft_itoa_base(va_arg(params, int), 10, 0));
			else if (*s == 'i')
				num_chars += ft_putstr(ft_itoa_base(va_arg(params, int), 10, 0));
			// else if (*s == 'u')
			else if (*s == 'x')
				num_chars += ft_putstr(ft_itoa_base(va_arg(params, int), 16, 0));
			else if (*s == 'X')
				num_chars += ft_putstr(ft_itoa_base(va_arg(params, int), 16, 1));
			else if (*s == '%')
				num_chars += ft_putchar('%');
		}
		else
			num_chars += ft_putchar(*s);
		s++;
	}
	va_end(params);
	return (num_chars);
}
