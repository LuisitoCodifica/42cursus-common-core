/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:38:44 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/12 00:44:11 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

static int	ft_parse_chr(int n)
{
	int	c;
	int	rem;

	rem = n % 10;
	c = rem + '0';
	return (c);
}

char	*ft_uitoa(unsigned int n)
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
		str[i++] = ft_parse_chr(n);
		n /= 10;
	}
	str[i] = 0;
	reverse(str, i);
	return (str);
}

