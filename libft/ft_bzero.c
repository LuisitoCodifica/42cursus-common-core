/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:43:40 by lolit-go          #+#    #+#             */
/*   Updated: 2024/04/12 13:02:58 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, int n)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
		ptr[i++] = 0;
	return (s);
}
