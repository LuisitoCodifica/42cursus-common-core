/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:28:09 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/18 20:57:07 by lolit-go         ###   ########.fr       */
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

static int	ft_n_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_parse_chr(unsigned int n, int upper)
{
	int	c;
	int	a;
	int	rem;

	if (upper)
		a = 'A';
	else
		a = 'a';
	rem = n % 16;
	if (rem > 9)
		c = (rem - 10) + a;
	else
		c = rem + '0';
	return (c);
}

char	*ft_itohex(unsigned int n, int upper)
{
	char	*str;
	int		len;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_n_len(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		str[i++] = ft_parse_chr(n, upper);
		n /= 16;
	}
	str[i] = 0;
	ft_reverse(str, i);
	return (str);
}
