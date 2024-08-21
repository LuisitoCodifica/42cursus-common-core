/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:47:37 by lolit-go          #+#    #+#             */
/*   Updated: 2024/08/21 17:46:25 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
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

static void	ft_parse_array(const char *s, char c, int **strs_pos, int size)
{
	int		i;
	int		j;

	*strs_pos = (int *) malloc((size * 2) * sizeof(int));
	if (*strs_pos)
	{
		j = 0;
		i = 0;
		while (s[i])
		{
			if (s[i] != c)
			{
				(*strs_pos)[j] = i;
				while (s[i] && s[i] != c)
					i++;
				(*strs_pos)[j + size] = (i - (*strs_pos)[j]);
				j++;
			}
			else
				i++;
		}
	}
}

static char	**ft_empty_array(void)
{
	char	**array;

	array = (char **) malloc(sizeof(char *));
	if (!array)
		return (NULL);
	array[0] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		*strs_pos;
	int		size;
	int		i;

	size = ft_count_words(s, c);
	if (size == 0)
		return (ft_empty_array());
	ft_parse_array(s, c, &strs_pos, size);
	if (!strs_pos)
		return (NULL);
	array = (char **) malloc((size + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = (char *) malloc((strs_pos[i + size] + 1) * sizeof(char));
		ft_strlcpy(array[i], (s + strs_pos[i]), (strs_pos[i + size] + 1));
		i++;
	}
	array[i] = 0;
	free(strs_pos);
	return (array);
}
