/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:11:32 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/08 10:49:59 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	f;

	i = 0;
	f = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == f)
			return (str + i);
		i++;
	}
	return (NULL);
}
