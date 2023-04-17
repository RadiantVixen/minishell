/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:19:23 by aatki             #+#    #+#             */
/*   Updated: 2023/04/17 00:22:02 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

#include  "../builtins/builtins.h"

#include "../libfta/libft.h"

typedef struct s_pipe
{
	char **cmd;
	char *infile;
	char *outfile;
	char *here_doc;
	struct s_pipe *next;
}t_pipe;

char	*check_env(char **env, char **cmd);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_free(char **p);
int		ft_strlen(char *s);
int		here_doc(char **av, int *infile);
void	ft_error(char *s);
void	here_docc(char **av);
void	here_doc_child(int *fd, char **av, char **env);
void	execution(char **cmd, char **env);
void	herep(char **av, char **env, int ac);
void	child_two(int *fd, char **av, char **env, int ac);
#endif