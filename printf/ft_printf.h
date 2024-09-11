/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:52:49 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/12 00:37:54 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(const char *s);

int		ft_strlcpy(char *dst, const char *src, int size);

char	*ft_strdup(const char *s);

int		ft_putchar(int c);

int		ft_putstr(const char *s);

char	*ft_itoa_base(int n, int base, int upper);

char	*ft_uitoa(unsigned int n);

char	*ft_mem_addr(const void *addr);

int		ft_printf(const char *s, ...);
