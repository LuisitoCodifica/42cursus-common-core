/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:28:21 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/07 02:41:48 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	int				i;

	dst_ptr = (unsigned char *) dst;
	src_ptr = (unsigned char *) src;
	if (!dst_ptr && !src_ptr)
		return (0);
	if (!n || *dst_ptr == *src_ptr)
		return (dst);
	i = 0;
	if (*dst_ptr < *src_ptr)
	{
		while (i < n)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
		while (n--)
			dst_ptr[n] = src_ptr[n];
	return (dst);
}
