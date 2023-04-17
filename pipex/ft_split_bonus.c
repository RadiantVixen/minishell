/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:46:22 by aatki             #+#    #+#             */
/*   Updated: 2023/04/17 00:32:37 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char	*sub;
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	if (start >= (unsigned int)ft_strlen(s))
// 		return (NULL);
// 	i = 0;
// 	while (s[start + i] && i < len)
// 		i++;
// 	sub = (char *)malloc(sizeof(char) * (i + 1));
// 	if (!sub)
// 		return (NULL);
// 	i = 0;
// 	while (s[i + start] && i < len)
// 	{
// 		sub[i] = s[start + i];
// 		i++;
// 	}
// 	sub[i] = 0;
// 	return (sub);
// }

// int	compt1(char const *s, char c)
// {
// 	int	i;
// 	int	cmpt;

// 	i = 0;
// 	cmpt = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 	{
// 		if ((s[0] != c && i == 0) || (s[i] != c && s[i - 1] == c))
// 			cmpt++;
// 		i++;
// 	}
// 	return (cmpt);
// }

// int	word(char const *s, char c)
// {
// 	int	k;

// 	k = 0;
// 	if (!s)
// 		return (0);
// 	while (s[k] && s[k] != c)
// 	{
// 		k++;
// 	}
// 	return (k);
// }

// char	**ft_free(char **p)
// {
// 	int	i;

// 	if (!p)
// 		return (NULL);
// 	i = 0;
// 	while (p[i])
// 	{
// 		free(p[i]);
// 		i++;
// 	}
// 	free(p);
// 	return (NULL);
// }

// char	**ft_split(char *s, char c)
// {
// 	int		i;
// 	int		j;
// 	char	**p;
// 	int		len;

// 	i = 0;
// 	j = 0;
// 	if (!s)
// 		return (NULL);
// 	len = compt1(s, c);
// 	p = malloc(sizeof(char *) * (len + 1));
// 	if (!p)
// 		return (NULL);
// 	while (*s && i < len)
// 	{
// 		while (*s == c)
// 			s++;
// 		p[i] = ft_substr(s, 0, word(s, c));
// 		if (!p[i])
// 			return (ft_free(p));
// 		s += word(s, c);
// 		i++;
// 	}
// 	p[i] = NULL;
// 	return (p);
// }
