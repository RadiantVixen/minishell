/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:23:47 by houaslam          #+#    #+#             */
/*   Updated: 2023/04/29 17:10:25 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isstring(char c)
{
	if (c == 124 || c == 60 || c == 62 || c == 34 || \
	c == 39 || c == 32 || c == 9)
		return (0);
	return (1);
}

int	ft_isstring_w_s(char c)
{
	if (c == 124 || c == 60 || c == 62 || c == 34 || c == 39)
		return (0);
	return (1);
}

int	ft_isstring_w_q(char c)
{
	if (c == 124 || c == 60 || c == 62 || c == 32 || c == 9)
		return (0);
	return (1);
}
