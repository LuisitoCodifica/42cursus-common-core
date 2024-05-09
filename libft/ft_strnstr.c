/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:33:47 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/09 02:04:13 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	char	*str;
	int		i;

	str = (char *) big;
	if ((!big && !little) || little[0] == 0)
		return (str);
	i = 0;
	while (str[i] && i < len)
	{
		if (!ft_strncmp((str + i), little, ft_strlen(little)))
			if (!((ft_strlen(little) + i) > len))
				return (str + i);
		i++;
	}
	return (0);
}
