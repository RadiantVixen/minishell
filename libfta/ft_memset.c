/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:08:47 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/03 10:39:45 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t b)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)str;
	i = 0;
	while (i < b)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
