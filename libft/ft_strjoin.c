/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:38:13 by aatki             #+#    #+#             */
/*   Updated: 2023/04/11 22:01:12 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	join = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
		join[ft_strlen(s1) + i] = s2[i];
	join[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (join);
}
