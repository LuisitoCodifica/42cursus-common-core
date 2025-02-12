/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:13:46 by lolit-go          #+#    #+#             */
/*   Updated: 2025/02/12 18:52:19 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"

# define R_SUCCESS 0
# define R_FAILURE 1

# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*ft_strdup(const char *s);

typedef struct s_line_node
{
	char				*content;
	ssize_t				length;
	ssize_t				newline_index;
	struct s_line_node	*next;
}						t_line;

t_line	*ft_line_new(char *content);
void	ft_line_addnode(t_line **lst, t_line *new);

/* temp */

int	ft_lstsize(t_line *lst);

#endif
