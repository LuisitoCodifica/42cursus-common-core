/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:25:08 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/06 21:51:29 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	int		i;

	s1 = (char *) s;
	i = 0;
	if (c > 127)
		c %= 256;
	while (i <= ft_strlen(s1))
	{
		if (c == s1[i])
			return (s1 + i);
		i++;
	}
	return (0);
}
