/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:11:29 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/21 02:44:36 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_n_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len = len + 1;
	}
	return (len);
}

char	*ft_parse(int n, int n_len)
{
	char	*n_str;

	n_str = (char *) malloc((n_len + 1) * sizeof(char));
	if (!n_str)
		return (0);
	n_str[n_len--] = 0;
	while (n_len >= 0)
	{
		n_str[n_len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (n_str);
}

char	*ft_parse_neg(int n, int n_len)
{
	char	*n_str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_str = (char *) malloc((n_len + 2) * sizeof(char));
	if (!n_str)
		return (0);
	n = -n;
	n_len = n_len + 1;
	n_str[n_len--] = 0;
	while (n_len)
	{
		n_str[n_len--] = (n % 10) + '0';
		n = n / 10;
	}
	n_str[n_len] = '-';
	return (n_str);
}

char	*ft_itoa(int n)
{
	int		n_len;

	if (n < 0)
		n_len = ft_n_len(-n);
	else
		n_len = ft_n_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	else if (n > 0)
		return (ft_parse(n, n_len));
	else
		return (ft_parse_neg(n, n_len));
}
