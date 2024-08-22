/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:40:08 by lolit-go          #+#    #+#             */
/*   Updated: 2024/08/22 15:22:43 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

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

void	*ft_memcpy(void *dst, const void *src, int n);

void	*ft_memmove(void *dst, const void *src, int n);

int		ft_memcmp(const void *s1, const void *s2, int n);

int		ft_atoi(const char *nptr);

void	*ft_calloc(int nmemb, int size);

char	*ft_strdup(const char *s);

char	*ft_substr(const char *s, size_t start, size_t len);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strtrim(const char *s1, const char *set);

char	*ft_strnstr(const char *big, const char *little, int len);

char	**ft_split(const char *s, char c);

char	*ft_itoa(int n);

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

#endif