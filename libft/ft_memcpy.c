/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:45:32 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/07 02:39:18 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	int				i;

	dst_ptr = (unsigned char *) dst;
	src_ptr = (unsigned char *) src;
	if (!dst_ptr && !src_ptr)
		return (0);
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst_ptr);
}
