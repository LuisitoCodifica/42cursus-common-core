/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:38:40 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/14 00:53:19 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_mem(char ***array, int num)
{
	int i = 0;
	int j = 0;
	*array = (char **) malloc(num * sizeof(char *));
	while (i < num) {
		(*array)[i] = (char *) malloc(num * sizeof(char));
		while (j < num) {
			(*array)[i][j] = (i + j + 'a');
			printf("%c ", array[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

static void	ft_parse_array(char **str, char **sizes, const char *s, char c)
{
	int	i;
	int	substr_len;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (ft_strchr((s + i), c))
			{
				substr_len = (ft_strchr((s + i), c) - s);

				printf("%2d: %2d (%s)\n", i, (substr_len - i),
				ft_substr(s, i, (substr_len - i)));
				*str = ft_strjoin(*str, ft_substr(s, i, (substr_len - i)));
				// *sizes = ft_strjoin(*str, (char *) (substr_len - i + '0'));
				
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
	// printf("(%s)\n", sizes);
	
	array = (char **) malloc(ft_strlen(sizes) * sizeof(char *));
	if (!array)
		return (0);

	// int num = 5;
	// ft_mem(&array, num);

	return (array);
}

int main() {
	char *str = "lorem ipsum dolor sit amet";
	ft_split(str, ' ');

	return 0;
}