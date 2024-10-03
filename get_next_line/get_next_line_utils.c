/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:22:52 by lolit-go          #+#    #+#             */
/*   Updated: 2024/10/03 18:18:18 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_get_len(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
	{
		// printf("%c\n", s[len]);
		if (s[len] == '\n')
			break ;
		len++;
	}
	return (len);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	// if (size < 0)
	// 	size = ft_strlen(dst) + ft_strlen(src) + 1 + ((size + 1) % size);
	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
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

	if (new_size <= size)
		return (ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		printf("-- HOLA --\n");
		return malloc(new_size);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
