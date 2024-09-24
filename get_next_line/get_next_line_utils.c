/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:22:52 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/24 20:19:36 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	dst_ptr = (unsigned char *) dst;
	src_ptr = (unsigned char *) src;
	if (!dst_ptr && !src_ptr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst_ptr);
}

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == size)
		return (ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return malloc(new_size);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (size < new_size)
		new_size = size;
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
