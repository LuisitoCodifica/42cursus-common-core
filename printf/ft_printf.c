/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:53:22 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/07 21:00:15 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_putchar(int c)
{
	write(0, &c, 1);
}

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(0, s, i);
}

int	ft_printf(const char *s, ...)
{
	int		num_chars;
	va_list	params;

	num_chars = 0;
	va_start(params, s);
	write(0, "\"", 1);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
				ft_putchar(va_arg(params, int));
			else if (*s == 's')
				ft_putstr(va_arg(params, char *));
			// else if (*s == 'p')
			// else if (*s == 'd')
			// else if (*s == 'i')
			// else if (*s == 'u')
			// else if (*s == 'x')
			// else if (*s == 'X')
			else if (*s == '%')
				ft_putchar('%');
		}
		else
			ft_putchar(*s);
		num_chars++;
		s++;
	}
	va_end(params);
	write(0, "\"", 1);
	return (num_chars);
}
