/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 05:15:11 by lolit-go          #+#    #+#             */
/*   Updated: 2024/08/21 09:43:32 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	if (start > i)
	{
		start = 0;
		len = 0;
	}
	else if (len > i)
		len = i;
	if ((start + len) > i)
		str = malloc(i - start + 1);
	else
		str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
