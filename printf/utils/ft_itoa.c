/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:41:57 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/18 20:32:47 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_reverse(char str[], int length)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = (length - 1);
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

static int	ft_n_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_check_neg(int n, int *neg)
{
	if (n < 0)
	{
		*neg = 1;
		return (-n);
	}
	*neg = 0;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		len;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = ft_check_neg(n, &neg);
	len = ft_n_len(n);
	str = (char *) malloc((len + neg + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[i++] = '-';
	str[i] = 0;
	ft_reverse(str, i);
	return (str);
}
