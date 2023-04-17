/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:56:19 by aatki             #+#    #+#             */
/*   Updated: 2022/10/27 11:53:32 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*x;

	i = 0;
	x = (unsigned char *) b;
	while (i < len)
	{
		x[i] = (unsigned char)c;
		i++;
	}
	return ((void *)x);
}
