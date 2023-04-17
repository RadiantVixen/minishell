/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 03:20:02 by aatki             #+#    #+#             */
/*   Updated: 2022/10/25 18:05:18 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t l)
{
	size_t	lens;
	size_t	lend;
	size_t	j;
	int		a;

	if (l == 0)
		return (ft_strlen(src));
	j = 0;
	lend = ft_strlen(dst);
	a = lend;
	lens = ft_strlen(src);
	if (l <= lend)
		return (l + lens);
	while (src[j] && lend < (l - 1))
	{
		dst[lend] = src[j];
		lend++;
		j++;
	}
	dst[lend] = '\0';
	return (a + lens);
}
