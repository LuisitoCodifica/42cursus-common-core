/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:43:32 by lolit-go          #+#    #+#             */
/*   Updated: 2025/03/21 20:18:00 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef RESET
#  define RESET "\e[0m"
# endif
# ifndef RED
#  define RED "\e[0;31m"
# endif
# ifndef GREEN
#  define GREEN "\e[0;32m"
# endif
# ifndef BLUE
#  define BLUE "\e[0;34m"
# endif

# ifndef R_FAILED
#  define R_FAILED -255
# endif
# ifndef NEWLINE_NOT_FOUND
#  define NEWLINE_NOT_FOUND -404
# endif

# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

void	_line_free(char **line);

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_strlcpy(char *dst, const char *src, int size);

#endif
