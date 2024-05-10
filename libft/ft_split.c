/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:37:17 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/10 21:34:24 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_getsize(const char *s, char c)
{
	int	size;
	int	substr_len;
	int	i;

	size = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (ft_strchr((s + i), c))
			{
				// printf("%d: \"%s\"\n", i, (s + i));
				substr_len = (ft_strchr(s, c) - s);
				size = (size + substr_len + 1);
				i = i + substr_len;
				continue;
			}
			break ;
		}
		i++;
	}
	return (size + ft_strlen(s + ++i) + 1);
}

char	**ft_tokenize(char **array, const char *s, char c)
{
	int	size;
	int	substr_len;
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (ft_strchr((s + i), c))
			{
				// printf("%d: \"%s\"\n", i, (s + i));
				substr_len = (ft_strchr(s, c) - s);
				size = (substr_len + 1);
				array[j] = (char *) malloc(size);
				if (!array[j])
					return (0);
				ft_strlcpy(array[j], (s + i), size);
				j++;
				i = i + substr_len;
				continue;
			}
			break ;
		}
		i++;
	}
	i--;
	substr_len = (ft_strchr(s, c) - s);
	size = (substr_len + 1);
	array[j] = (char *) malloc(size);
	if (!array[j])
		return (0);
	ft_strlcpy(array[j], (s + i), size);
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		size;

	size = ft_getsize(s, c);
	// printf("%d\n", size);
	array = (char**) malloc(size);
	if (!array)
		return (0);
	return (ft_tokenize(array, s, c));
}

int main() {
	char *str = "lorem ipsum dolor sit amet";
	char **array = ft_split(str, ' ');
	int i = 0;
	
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}

	return (0);
}