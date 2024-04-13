/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:45:32 by lolit-go          #+#    #+#             */
/*   Updated: 2024/04/12 15:54:01 by lolit-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *) dst;
	i = 0;
	while ((src + i) && i < n)
		ptr[i++] = *(unsigned char *) src++;
	return (dst);
}
