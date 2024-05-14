/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:38:40 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/14 17:27:06 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_mem(char ***array, char *str, char *sizes, int len)
{
	int i = 0;
	int j = 0;
	*array = (char **) malloc(len * sizeof(char *));
	while (i < len) {
		(*array)[i] = (char *) malloc((sizes[i] + 1) * sizeof(char));
		ft_strlcpy((*array)[i], (str + j), (sizes[i] - '0' + 1));
		// while (j < len) {
		// 	(*array)[i][j] = (i + j + 'a');
		// 	printf("%c ", array[i][j]);
		// 	j++;
		// }
		// printf("\n");
		// j = 0;
		j = j + (sizes[i] - '0');
		i++;
	}
}

static void	ft_parse_array(char **str, char **sizes, const char *s, char c)
{
	int	i;
	int	j;
	int	substr_len;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (ft_strchr((s + i), c))
			{
				substr_len = (ft_strchr((s + i), c) - s);

				printf("%2d: %2d (%s)\n", i, (substr_len - i), ft_substr(s, i, (substr_len - i)));
				*str = ft_strjoin(*str, ft_substr(s, i, (substr_len - i)));
				// *sizes = ft_strjoin(*sizes, (char *) (substr_len - i + '0'));
				*sizes = ft_strjoin(*sizes, "0");
				(*sizes)[j++] += (substr_len - i);
				// j++;
				
				i = substr_len;
				continue ;
			}
			break ;
		}
		i++;
	}
	if (i == (substr_len + 1))
	{
		printf("%2d: %2d (%s)\n", i, ft_strlen(s + i), (s + i));
		*str = ft_strjoin(*str, ft_substr(s, i, ft_strlen(s + i)));
		// *sizes = ft_strjoin(*str, (char *) (ft_strlen(s + i)));
		*sizes = ft_strjoin(*sizes, "0");
		(*sizes)[j] += (ft_strlen(s + i));
	}
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	char	*str;
	char	*sizes;

	str = ft_strdup("");
	sizes = ft_strdup("");
	ft_parse_array(&str, &sizes, s, c);
	printf("(%s)\n", str);
	printf("(%s)\n", sizes);
	
	array = (char **) malloc(ft_strlen(sizes) * sizeof(char *));
	if (!array)
		return (0);

	int len = ft_strlen(sizes);
	ft_mem(&array, str, sizes, len);

	return (array);
}

int main() {
	char *str = "lorem ipsum dolor sit amet";
	char **array = ft_split(str, ' ');

	int i = 0;
		printf("\n");
		printf("\"%s\"\n", array[i++]);
		printf("\"%s\"\n", array[i++]);
		printf("\"%s\"\n", array[i++]);
		printf("\"%s\"\n", array[i++]);
		printf("\"%s\"\n", array[i]);
	// while (array[i]) {
	// 	printf("(%s)\n", array[i]);
	// 	i++;
	// }

	return 0;
}