/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 08:02:10 by aatki             #+#    #+#             */
/*   Updated: 2022/10/27 22:08:28 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compteur(long *nb, int *sign)
{
	int		cmpt;
	long	i;

	cmpt = 0;
	i = *nb;
	if (*nb < 0)
	{
		*sign = -1;
		*nb *= -1;
	}
	else
		*sign = 1;
	if (i < 0)
	{
		i = i * (-1);
		cmpt++;
	}
	while (i >= 1)
	{
		i = i / 10;
		cmpt++;
	}
	return (cmpt);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		cmpt;
	long	i;
	int		sign;
	long	nb;

	nb = n;
	i = n;
	cmpt = compteur(&nb, &sign);
	if (i == 0)
		return (ft_strdup("0"));
	itoa = ft_calloc(1, cmpt + 1);
	if (!itoa)
		return (NULL);
	i = cmpt;
	itoa[i--] = '\0';
	while (nb)
	{
		itoa[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	if (sign == -1)
		itoa[0] = '-';
	return (itoa);
}
