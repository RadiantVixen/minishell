/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:39:11 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/03 18:34:00 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s1;
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	s1 = malloc(sizeof(char) * ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	if (!s1)
		return (NULL);
	while (i < ft_strlen(s2))
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
