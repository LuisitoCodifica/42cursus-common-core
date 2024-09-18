/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:00:48 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/18 20:54:37 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
		str = ft_itoa(va_arg(params, int));
	else if (specifier == 'i')
		str = ft_itoa(va_arg(params, int));
	else if (specifier == 'u')
		str = ft_uitoa(va_arg(params, unsigned int));
	else if (specifier == 'x')
		str = ft_itohex(va_arg(params, long), 0);
	else if (specifier == 'X')
		str = ft_itohex(va_arg(params, long), 1);
	num_chars = ft_putstr(str);
	free(str);
	return (num_chars);
}

int	ft_parse(const char specifier, va_list params)
{
	int	num_chars;

	if (ft_check_spec(specifier, "cs%"))
		num_chars = ft_put_non_mem(specifier, params);
	else if (ft_check_spec(specifier, "pdiuxX"))
		num_chars = ft_put_mem(specifier, params);
	return (num_chars);
}
