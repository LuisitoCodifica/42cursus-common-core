/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:40:01 by lolit-go          #+#    #+#             */
/*   Updated: 2024/04/11 14:23:04 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		if (size == 0)
			break ;
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
