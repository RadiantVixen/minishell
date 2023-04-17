/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:14:33 by aatki             #+#    #+#             */
/*   Updated: 2023/04/17 00:29:56 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	command(char **cmd_arg, int fdout,char **env)
{
		if (!strncmp(cmd_arg[0], "echo", 4))
			ft_echo(cmd_arg++, fdout, env);
		else if (!strncmp(cmd_arg[0], "env", 3))
			ft_env(env, cmd_arg++, fdout);
		else if (!strncmp(cmd_arg[0], "export", 6))
			ft_export(env,cmd_arg++, fdout);
		else if (!strncmp(cmd_arg[0], "cd", 2))
			ft_cd(env, cmd_arg++);
		else if (!strncmp(cmd_arg[0], "exit", 4))
			ft_exit(cmd_arg++);
		else if (!strncmp(cmd_arg[0], "unset", 5))
			ft_unset(env, cmd_arg++);
		else if (!strncmp(cmd_arg[0], "pwd", 3))
			ft_pwd(fdout);
		else
			execution(cmd_arg,env);
}

void	execution(char **cmd, char **env)
{
	char	*path;

	path = NULL;
	if (access(cmd[0], X_OK) == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
			ft_error("command can't executude");
	}
	else
	{
		path = check_env(env, cmd);
		if (execve(path, cmd, env) < 0)
		ft_error("command can't executude");
	}
	free(path);
	ft_free(cmd);
}

int	ft_infile(char *s, int *i)
{
	int	infile;

	infile = open(s, O_RDWR, 0644);
	if (infile < 0)
		ft_error("file can't open");
	*i = 2;
	return (infile);
}

void	child_one(t_pipe *pipee, int *fd,char **env)
{
	int	i;
	int	ph[2];
	int	id;

	fd[0] = ft_infile(pipee->infile, &i);
	while (pipee->next)
	{
		if (pipe(ph) < 0)
			ft_error("cant pipe in child one");
		id = fork();
		if (id < 0)
			ft_error("cant fork in child one");
		if (id == 0)
		{
			if (dup2(fd[0], 0) < 0)
				ft_error("cant dup 1 in child one");
			if (dup2(ph[1], 1) < 0)
				ft_error("cant dup 2 in child one");
			command(pipee->cmd,ph[1], env);
		}
		*fd = dup(ph[0]);
		close(ph[1]);
		pipee=pipee->next;
	}
}

void	child_two2(t_pipe *pipee ,int *fd,char **env)
{
	int	outfile;

	outfile = open(pipee->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 0)
		ft_error("file can't opennn");
	if (dup2(*fd, 0) < 0)
		ft_error("can't 2 dup in child 2");
	if (dup2(outfile, 1) < 0)
		ft_error("can't 1 dup in child 2");
	command(pipee->cmd,outfile, env);
}

void	pipex(t_pipe  *pipe, char **env)
{
	int	fd;
	int	id2;
	int	id;

	id = 0;
	child_one(pipe, &fd ,env);
	id2 = fork();
	if (id2 == 0)
		child_two2(pipe,&fd,env);
	waitpid(id2, NULL, 0);
}


int main()
{
	printf("fiinalyyyyy\n");
}