/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:47:12 by aatki             #+#    #+#             */
/*   Updated: 2023/04/17 00:11:55 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	herep(char **av, char **env, int ac)
// {
// 	int	fd[2];
// 	int	id2;
// 	int	id;

// 	if (ac == 6)
// 	{
// 		here_docc(av);
// 		pipe(fd);
// 		id = fork();
// 		if (id == 0)
// 			here_doc_child(fd, av, env);
// 		id2 = fork();
// 		if (id2 == 0)
// 			child_two(fd, av, env, ac);
// 	}
// }

// void	child_two(int *fd, char **av, char **env, int ac)
// {
// 	int	outfile;

// 	outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
// 	if (outfile < 0)
// 		ft_error("file can't opennn");
// 	if (close(fd[1]) < 0)
// 		ft_error("file can't close in child 2");
// 	if (dup2(fd[0], 0) < 0)
// 		ft_error("can't 2 dup in child 2");
// 	if (dup2(outfile, 1) < 0)
// 		ft_error("can't 1 dup in child 2");
// 	execution(av[ac - 2], env);
// }

// void	here_docc(char **av)
// {
// 	int		infile;
// 	char	*tmp;

// 	tmp = NULL;
// 	infile = open("../.file.tmp", O_RDWR | O_CREAT, 0777);
// 	if (infile < 0)
// 		ft_error("file can't open");
// 	write(1, "here_doc> ", 10);
// 	tmp = get_next_line(0);
// 	while (tmp)
// 	{
// 		if ((ft_strncmp(tmp, av[2], ft_strlen(tmp) - 1) == 0) && ft_strlen(tmp)
// 			- 1 == ft_strlen(av[2]))
// 		{
// 			free(tmp);
// 			break ;
// 		}
// 		write(1, "here_doc> ", 10);
// 		write(infile, tmp, ft_strlen(tmp));
// 		free(tmp);
// 		tmp = get_next_line(0);
// 	}
// 	close(infile);
// }

// void	here_doc_child(int *fd, char **av, char **env)
// {
// 	int	infile;

// 	infile = open("../.file.tmp", O_RDONLY);
// 	close(fd[0]);
// 	if (dup2(infile, 0) < 0)
// 		ft_error("can't dup");
// 	if (dup2(fd[1], 1) < 0)
// 		ft_error("can't dup");
// 	unlink("../.file.tmp");
// 	execution(av[3], env);
// }
