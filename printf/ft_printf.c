/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:53:22 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/07 18:05:46 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(0, &c, 1);
}

int	ft_printf(const char *s, ...)
{
	int	count;

	write(0, "\"", 1);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				ft_putchar('%');
			else
				s--;
		}
		else
			ft_putchar(*s);
		count++;
		s++;
	}
	write(0, "\"", 1);
	return (count);
}
