/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:34 by aatki             #+#    #+#             */
/*   Updated: 2022/10/27 22:27:09 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	f(unsigned int a, char b)
// {
// 	a = 1;
// 	return (ft_toupper(b));
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;

	if (!s && !f)
		return (NULL);
	i = 0;
	mapi = malloc(ft_strlen(s) + 1);
	if (!mapi)
		return (NULL);
	while (s[i])
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
