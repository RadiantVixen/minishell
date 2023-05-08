/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmetter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:13:31 by aatki             #+#    #+#             */
/*   Updated: 2023/05/08 22:58:05 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

void	ft_lstadd_back2(t_pipe **lst, t_pipe *new)
{
	t_pipe	*temp;

	if (!new)
		return ;
	if (*lst)
	{
		temp = (*lst);
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}

void	affiche_pipe(t_pipe *pipe)
{
	int	i;

	while (pipe)
	{
		i = 0;
		while (pipe->cmd[i])
		{
			i++;
		}
		printf("infile=%s\n", pipe->infile);
		printf("outfile=%s\n", pipe->outfile);
		printf("here_doc=%s\n", pipe->outfile);
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
		ft_free(pipe->cmd);
		pipe = pipe->next;
		free(tmp);
		tmp = NULL;
	}
}

void	files(t_pipe *tmp, t_data *data)
{
	(tmp)->infile = NULL;
	(tmp)->outfile = NULL;
	(tmp)->here_doc = NULL;
	(tmp)->here_doc_out = NULL;
	while (data->exec->file)
	{
		if (data->exec->file->type == 60)
			(tmp)->infile = data->exec->file->file;
		else if (data->exec->file->type == 62)
			(tmp)->outfile = data->exec->file->file;
		else if (data->exec->file->type == 5)
			(tmp)->here_doc = data->exec->file->file;
		else if (data->exec->file->type == 6)
			(tmp)->here_doc_out = data->exec->file->file;
		data->exec->file = data->exec->file->next;
	}
}

void	transmettre(t_data *data, char ***env, char ***export)
{
	t_pipe	*tmp;
	t_pipe	*pipe;

	pipe = NULL;
	tmp = NULL;
	while (data->exec)
	{
		tmp = malloc(sizeof(t_pipe));
		(tmp)->cmd = ft_split(data->exec->value, '*');
		free(data->exec->value);
		files(tmp, data);
		tmp->next = NULL;
		free(data->exec);
		data->exec = data->exec->next;
		ft_lstadd_back2(&pipe, tmp);
	}
	pipex(pipe, env, export);
	free_pipe(pipe);
}
