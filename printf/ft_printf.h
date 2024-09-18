/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:52:49 by lolit-go          #+#    #+#             */
/*   Updated: 2024/09/18 20:57:53 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(const char *s);

int		ft_strlcpy(char *dst, const char *src, int size);

char	*ft_strdup(const char *s);

int		ft_putchar(int c);

int		ft_putstr(const char *s);

char	*ft_itoa(int n);

char	*ft_itohex(unsigned int n, int upper);

char	*ft_uitoa(unsigned int n);

char	*ft_mem_addr(const void *addr);

int		ft_check_spec(const char c, const char *specifiers);

int		ft_validate(const char *s);

int		ft_parse(const char specifier, va_list params);

int		ft_printf(const char *s, ...);

#endif
