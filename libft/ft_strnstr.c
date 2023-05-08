/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:21:20 by houaslam          #+#    #+#             */
/*   Updated: 2022/10/30 11:26:42 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen((char *)small) == 0)
		return ((char *)big);
	if (!big && len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == small[j] && i + j < len && small[j] && big[i + j])
		{
			j++;
		}
		if (small[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
