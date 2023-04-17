/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:23:47 by houaslam          #+#    #+#             */
/*   Updated: 2023/04/11 22:34:13 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstring(char c)
{
	if (c == 124 || c == 60 || c == 62 || c == 34 || \
	c == 39 || c == 32 || c == 9)
		return (0);
	return (1);
}

int	ft_isstring_(char c)
{
	if (c == 124 || c == 60 || c == 62 || c == 34 || c == 39)
		return (0);
	return (1);
}

int	ft_isstring__(char c)
{
	if (c == 124 || c == 60 || c == 62 || c == 32 || c == 9)
		return (0);
	return (1);
}
