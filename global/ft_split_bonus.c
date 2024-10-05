/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:46:22 by aatki             #+#    #+#             */
/*   Updated: 2023/06/17 18:47:28 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executionn/pipex/pipex_bonus.h"

void	ft_lstadd_back2(t_pipe **lst, t_pipe **new)
{
	t_pipe	*temp;

	if (!new)
		return ;
	if (*lst)
	{
		temp = (*lst);
		while (temp->next)
			temp = temp->next;
		temp->next = *new;
	}
	else
		*lst = *new;
}

void	affiche_pipe(t_pipe *pipe)
{
	int	i;

	while (pipe)
	{
		i = 0;
		while (pipe->cmd[i])
			i++;
		pipe = pipe->next;
	}
}

void	free_pipe(t_pipe *pipe)
{
	t_pipe	*tmp;

	if (!pipe)
		return ;
	while (pipe)
	{
		tmp = pipe;
		pipe = pipe->next;
		ft_free(tmp->cmd);
		free(tmp);
	}
}
