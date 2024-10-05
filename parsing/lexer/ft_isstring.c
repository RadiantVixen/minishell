/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:23:47 by houaslam          #+#    #+#             */
/*   Updated: 2023/05/31 18:54:50 by houaslam         ###   ########.fr       */
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

t_file	*copy_f(t_file *file)
{
	t_file	*copy;
	t_file	*tmp;

	copy = NULL;
	tmp = file;
	while (tmp)
	{
		ft_lstadd_back_file(&copy, \
		ft_lstnew_file(tmp->file, tmp->type, tmp->expand));
		tmp = tmp->next;
	}
	return (copy);
}
