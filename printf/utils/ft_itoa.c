/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:41:57 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/10 16:33:55 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	reverse(char str[], int length)
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

static int	ft_check_neg(int n, int base, int *neg)
{
	if (n < 0 && base == 10)
	{
		*neg = 1;
		return (-n);
	}
	*neg = 0;
	return (n);
}

static int	ft_parse_chr(int n, int base, int upper)
{
	int	c;
	int	a;
	int	rem;

	if (upper)
		a = 'A';
	else
		a = 'a';
	rem = n % base;
	if (rem > 9)
		c = (rem - 10) + a;
	else
		c = rem + '0';
	return (c);
}

char	*ft_itoa_base(int n, int base, int upper)
{
	char	*str;
	int		neg;
	int		len;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = ft_check_neg(n, base, &neg);
	len = ft_n_len(n);
	str = (char *) malloc((len + neg + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		str[i++] = ft_parse_chr(n, base, upper);
		n /= base;
	}
	if (neg)
		str[i++] = '-';
	str[i] = 0;
	reverse(str, i);
	return (str);
}
