/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:53:25 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/07 18:19:34 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strs(char *str, char *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str);
	while (i < j && ft_strchr(c, str[i]) != 0)
		i++;
	return (i);
}

static size_t	ft_stre(char *str, char *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str);
	while (i < j && ft_strchr(c, str[j - i - 1]) != 0)
		i++;
	return (j - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*p;
	int		s;
	int		e;

	i = 0;
	if (!set || !s1)
		return (NULL);
	s = ft_strs((char *)s1, (char *)set);
	e = ft_stre((char *)s1, (char *)set);
	if (s >= e)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (e - s + 1));
	if (!p)
		return (NULL);
	while (s < e && s1[s])
	{
		p[i] = s1[s];
		i++;
		s++;
	}
	p[i] = '\0';
	return (p);
}
