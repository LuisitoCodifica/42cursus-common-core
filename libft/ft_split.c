/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:47:37 by lolit-go          #+#    #+#             */
/*   Updated: 2024/08/22 10:00:00 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			words += 1;
		}
		else
			i++;
	}
	return (words);
}

static void	push(char *str_arr, const char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str_arr[i] = s[i];
		i++;
	}
	str_arr[i] = 0;
}

static void	free_memory(char **str_arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

static int	parse(char **str_arr, const char *s, char c, int j)
{
	int	s_start;
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			s_start = i;
			while (s[i] && s[i] != c)
				i++;
			str_arr[j] = (char *) malloc(((i - s_start) + 1) * sizeof(char));
			if (!str_arr[j])
			{
				free_memory(str_arr, j);
				return (0);
			}
			push(str_arr[j], (s + s_start), (i - s_start));
			j++;
		}
		else
			i++;
	}
	str_arr[j] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**str_arr;
	int		words;

	words = count_words(s, c);
	str_arr = (char **) malloc((words + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	if (!parse(str_arr, s, c, 0))
		return (NULL);
	return (str_arr);
}
