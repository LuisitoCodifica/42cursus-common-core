/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:28:35 by lolit-go          #+#    #+#             */
/*   Updated: 2024/08/21 17:51:19 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcmp(int c, const char *set)
{
	while (*set)
		if (c == *(set++))
			return (1);
	return (0);
}

static char	*ft_setstr(const char *s1, int start, int len)
{
	char	*str;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s1 + start), (len + 1));
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	start;
	int	end;

	start = 0;
	end = (ft_strlen(s1) - 1);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_charcmp(s1[start], set))
		start++;
	while (ft_charcmp(s1[end], set))
		end--;
	return (ft_setstr(s1, start, end - (start - 1)));
}
