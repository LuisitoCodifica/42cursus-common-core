/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:22:37 by lolit-go          #+#    #+#             */
/*   Updated: 2025/01/11 21:02:15 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memchr(void *s, int c, int n)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return (ptr + i);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, int n)
{
	int	i;

	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	int				i;

	dst_ptr = (unsigned char *) dst;
	src_ptr = (unsigned char *) src;
	if (!dst_ptr && !src_ptr)
		return (0);
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst_ptr);
}

void	*ft_memset(void *s, int c, int n)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
		ptr[i++] = (unsigned char) c;
	return (s);
}
