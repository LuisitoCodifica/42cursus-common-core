/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:53:22 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/16 14:02:12 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			num_chars += ft_parse(*(++s), params);
		else
			num_chars += ft_putchar(*s);
		s++;
	}
	va_end(params);
	return (num_chars);
}
