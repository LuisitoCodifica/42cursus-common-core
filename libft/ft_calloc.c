/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:54:13 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/06 17:59:49 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}