/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:04:34 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/06 21:43:21 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		i;

	s1 = (char *) s;
	i = ft_strlen(s1);
	if (c > 127)
		c %= 256;
	while (i >= 0)
	{
		if (c == s1[i])
			return (s1 + i);
		i--;
	}
	return (0);
}
