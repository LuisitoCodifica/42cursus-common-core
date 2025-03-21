/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:44:44 by lolit-go          #+#    #+#             */
/*   Updated: 2025/03/21 19:39:24 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void
	_line_free(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
}

int
	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char
	*ft_strchr(const char *s, int c)
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
	return (NULL);
}

int
	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;

	if (size == 0)
		return (ft_strlen(src));
	if (size < 0)
		size = ft_strlen(src) + 1 + ((size + 1) % size);
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
