/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:47:37 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/16 05:02:06 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_parse_array(int *size, const char *s, char c)
{
	char	*str;
	char	c_string[2];
	int		i;

	str = ft_strdup("");
	c_string[0] = c;
	c_string[1] = '\0';
	*size = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				str = ft_strjoin(str, ft_substr(s, i++, 1));
			str = ft_strjoin(str, c_string);
			*size += 1;
		}
		else
			i++;
	}
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	char	*str;
	int		size;
	int		len;
	int		i;

	str = ft_parse_array(&size, s, c);
	array = (char **) malloc((size + 1) * sizeof(char *));
	if (!array)
		return (0);
	i = 0;
	while (i < size)
	{
		len = (ft_strchr(str, c) - str);
		array[i] = (char *) malloc((len + 1) * sizeof(char));
		if (!array[i])
			return (0);
		ft_strlcpy(array[i], str, (len + 1));
		str = (str + len + 1);
		i++;
	}
	array[i] = 0;
	return (array);
}

int main() {
	// char *s = "      split       this for   me  !       ";
	char *s = "xxxxxxxxhello!";

	char **result = ft_split(s, 'x');
	if (!result)
		printf("TEST_FAILED\n");
	else
		printf("TEST_SUCCESS\n");
	
	int i = 0;
	while (result[i])
	{
		printf("%2d: (%s)\n", i + 1, result[i]);
		i++;
	}

	return (0);
}