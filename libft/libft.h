/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:40:08 by lolit-go          #+#    #+#             */
/*   Updated: 2024/04/12 12:50:25 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_tolower(int c);

int		ft_toupper(int c);

int		ft_strlen(const char *s);

int		ft_strncmp(const char *s1, const char *s2, int n);

int		ft_strlcpy(char *dst, const char *src, int size);

int		ft_strlcat(char *dst, const char *src, int size);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

void	*ft_bzero(void *s, int n);

void	*ft_memset(void *s, int c, int n);

void	*ft_memchr(void *s, int c, int n);
