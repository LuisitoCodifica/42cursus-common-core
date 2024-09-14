/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:53:22 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/14 23:35:47 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_validate(const char *s, const char *specifiers)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			while (specifiers[i])
			{
				if (*s == specifiers[i])
					return (0);
				i++;
			}
			i = 0;
		}
		s++;
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	char	*str;
	int		num_chars;
	int		clear;
	va_list	params;

	if (ft_validate(s, "cspdixX%"))
		return (-1);
	num_chars = 0;
	va_start(params, s);
	while (*s)
	{
		str = NULL;
		clear = 1;
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
			{
				ft_putchar(va_arg(params, int));
				clear = 0;
			}
			else if (*s == 's')
			{
				str = va_arg(params, char *);
				clear = 0;
			}
			else if (*s == 'p')
				str = ft_mem_addr(va_arg(params, void *));
			else if (*s == 'd')
				str = ft_itoa_base(va_arg(params, int), 10, 0);
			else if (*s == 'i')
				str = ft_itoa_base(va_arg(params, int), 10, 0);
			else if (*s == 'u')
				str = ft_uitoa(va_arg(params, unsigned int));
			else if (*s == 'x')
				str = ft_itoa_base(va_arg(params, int), 16, 0);
			else if (*s == 'X')
				str = ft_itoa_base(va_arg(params, int), 16, 1);
			else if (*s == '%')
			{
				ft_putchar('%');
				clear = 0;
			}
			if (!str)
				num_chars += 1;
			else
				num_chars += ft_putstr(str);
			if (clear)
				free(str);
		}
		else
			num_chars += ft_putchar(*s);
		s++;
	}
	va_end(params);
	return (num_chars);
}
