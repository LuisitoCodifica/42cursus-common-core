/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:38:40 by lolit-go          #+#    #+#             */
/*   Updated: 2024/05/13 21:30:18 by lolit-go         ###   ########.fr       */
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

char	**ft_split(const char *s, char c)
{
	char	**array;
	

	
	// int num = 5;
	// ft_mem(&array, num);

	return (array);
}

int main() {
	char *str = "lorem ipsum dolor sit amet";
	ft_split(str, ' ');

	return 0;
}