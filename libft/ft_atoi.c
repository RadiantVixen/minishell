/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:25:39 by aatki             #+#    #+#             */
/*   Updated: 2022/10/27 11:46:16 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_max(unsigned long long a, int sign)
{
	if (a >= 9223372036854775807 && sign == 1)
		return (-1);
	else if (a > 9223372036854775807 && sign == -1)
		return (1);
	return ((int)a * sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					s;
	unsigned long long	a;

	i = 0;
	s = 1;
	a = 0;
	while (str[i] == '\t' || str[i] == '\n' \
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r' \
			|| str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	return (ft_max(a, s));
}
