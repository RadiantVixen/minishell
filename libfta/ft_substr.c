/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:53:52 by houaslam          #+#    #+#             */
/*   Updated: 2023/04/16 23:07:46 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;
	size_t			k;

	if (!s)
		return (NULL);
	k = ft_strlen((char *)s);
	if (start > k)
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s + start))
		len = ft_strlen((char *)s + start);
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (NULL);
	while (i < len && start < k)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
