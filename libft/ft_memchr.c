/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:47:41 by lolit-go          #+#    #+#             */
/*   Updated: 2024/04/12 12:59:19 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, int n)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return (ptr + i);
		i++;
	}
	return (0);
}
