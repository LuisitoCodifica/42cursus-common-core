/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:28:21 by lolit-go          #+#    #+#             */
/*   Updated: 2024/10/24 01:40:38 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int n)
{
	int	i;

	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dst);
}
