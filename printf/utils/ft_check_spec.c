/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:02:15 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/16 14:02:56 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_check_spec(const char c, const char *specifiers)
{
	int	i;

	i = 0;
	while (specifiers[i])
	{
		if (c == specifiers[i])
			return (1);
		i++;
	}
	return (0);
}
