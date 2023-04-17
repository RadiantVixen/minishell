/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:11:13 by houaslam          #+#    #+#             */
/*   Updated: 2022/10/30 11:26:23 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	char			*p;
	char			f;

	i = 0;
	f = (char)c;
	p = (char *)str;
	while (p[i] != f)
	{
		if (p[i] == '\0')
			return (NULL);
		i++;
	}
	return (p + i);
}
