/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:46:06 by houaslam          #+#    #+#             */
/*   Updated: 2022/10/30 11:26:37 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*p;
	size_t	len;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
