/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:01:46 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/16 14:03:33 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_validate(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			if (ft_check_spec(*(++s), "cspdiuxX%"))
				return (0);
		s++;
	}
	return (1);
}
