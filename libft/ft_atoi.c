/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:17:27 by lolit-go          #+#    #+#             */
/*   Updated: 2024/04/15 14:35:37 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_is_valid(int c, int next)
{
	if (c == ' ')
		return (203);
	if ((c >= '\011' && c <= '\015')
		|| c == '+')
		return (202);
	if (!ft_isdigit(c))
		return (201);
	if (ft_isdigit(c) && !ft_isdigit(next))
		return (200);
	return (0);
}

static int	ft_convert_to_num(const char *nptr)
{
	int	n;
	int	check;

	n = 0;
	while (*nptr)
	{
		check = ft_check_is_valid(*nptr, *(nptr + 1));
		if (check == 203 || check == 202)
		{
			nptr++;
			continue ;
		}
		if (check == 201)
			return (n);
		n = n * 10 + *nptr - '0';
		if (check == 200)
			return (n);
		nptr++;
	}
	return (n);
}

int	ft_atoi(const char *nptr)
{
	int	neg;

	neg = 0;
	if ((*nptr == '-' || *nptr == '+') && !ft_isdigit(*(nptr + 1)))
		return (0);
	if (*nptr == '-')
	{
		neg = 1;
		nptr++;
	}
	if (neg)
		return (ft_convert_to_num(nptr) * -1);
	return (ft_convert_to_num(nptr));
}
