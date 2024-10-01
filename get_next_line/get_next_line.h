/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:02:42 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/25 19:50:54 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_get_len(const char *s);

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_realloc(void *ptr, size_t size, size_t new_size);

char	*get_next_line(int fd);

#endif