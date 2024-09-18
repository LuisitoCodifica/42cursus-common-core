/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:33:34 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/18 20:59:36 by lolit-go         ###   ########.fr       */
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

static int	ft_n_len(unsigned long n)
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

static int	ft_parse_chr(unsigned long n)
{
	int	c;
	int	rem;

	rem = n % 16;
	if (rem > 9)
		c = (rem - 10) + 'a';
	else
		c = rem + '0';
	return (c);
}

char	*ft_mem_addr(const void *addr)
{
	char			*str;
	int				len;
	int				i;
	unsigned long	n;

	n = (unsigned long) addr;
	if (n == 0)
		return (ft_strdup("(nil)"));
	len = ft_n_len(n);
	str = (char *) malloc((len + 3) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		str[i++] = ft_parse_chr(n);
		n /= 16;
	}
	str[i++] = 'x';
	str[i++] = '0';
	str[i] = 0;
	reverse(str, i);
	return (str);
}
