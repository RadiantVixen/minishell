/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:48:07 by aatki             #+#    #+#             */
/*   Updated: 2022/10/27 12:11:08 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (0);
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_calloc(1, 1));
	i = 0;
	while (s[start + i] && i < len)
		i++;
	sub = (char *)malloc (sizeof(char) * (i + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
