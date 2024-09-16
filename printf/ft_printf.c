/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:53:22 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/16 10:55:57 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_spec(const char c, const char *specifiers)
{
	int	i;

	i = 0;
	while (specifiers[i])
	{
		if (c == specifiers[i])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_validate(const char *s)
{
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!ft_check_spec(*s, "cspdiuxX%"))
				return (0);
		}
		s++;
	}
	return (1);
}

static int	ft_put_non_mem(const char specifier, va_list params)
{
	int	num_chars;

	if (specifier == 'c')
		num_chars = ft_putchar(va_arg(params, int));
	else if (specifier == '%')
		num_chars = ft_putchar('%');
	else if (specifier == 's')
		num_chars = ft_putstr(va_arg(params, char *));
	return (num_chars);
}

static int	ft_put_mem(const char specifier, va_list params)
{
	char	*str;
	int		num_chars;

	if (specifier == 'p')
		str = ft_mem_addr(va_arg(params, void *));
	else if (specifier == 'd')
		str = ft_itoa_base(va_arg(params, int), 10, 0);
	else if (specifier == 'i')
		str = ft_itoa_base(va_arg(params, int), 10, 0);
	else if (specifier == 'u')
		str = ft_uitoa(va_arg(params, unsigned int));
	else if (specifier == 'x')
		str = ft_itoa_base(va_arg(params, int), 16, 0);
	else if (specifier == 'X')
		str = ft_itoa_base(va_arg(params, int), 16, 1);
	num_chars = ft_putstr(str);
	free(str);
	return (num_chars);
}

static int	ft_parse(const char specifier, va_list params)
{
	int	num_chars;

	if (!ft_check_spec(specifier, "cs%"))
	{
		printf("hola\n");
		num_chars = ft_put_non_mem(specifier, params);
	}
	else if (!ft_check_spec(specifier, "pdiuxX"))
	{
		printf("adios\n");
		num_chars = ft_put_mem(specifier, params);
	}
	return (num_chars);
}

int	ft_printf(const char *s, ...)
{
	int		num_chars;
	va_list	params;

	if (ft_validate(s))
		return (-1);
	num_chars = 0;
	va_start(params, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			num_chars += ft_parse(*s, params);
		}
		else
			num_chars += ft_putchar(*s);
		s++;
	}
	va_end(params);
	return (num_chars);
}
