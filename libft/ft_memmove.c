/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 06:20:55 by aatki             #+#    #+#             */
/*   Updated: 2022/10/27 16:49:11 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*c;

	if (!dst && !src)
		return (NULL);
	s = (unsigned char *)dst;
	c = (unsigned char *)src;
	if (src < dst)
	{
		while (len--)
		{
			*(s + len) = *(c + len);
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
