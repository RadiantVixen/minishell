/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:32:03 by houaslam          #+#    #+#             */
/*   Updated: 2023/04/17 00:34:14 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libfta/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_cmd
{
	char			*cmd;
	struct t_cmd	*next_cmd;
}					t_cmd;

typedef struct tj_pipe
{
	t_cmd			c;
	struct t_pipe	*next_pipe;
	char			*infile;
	char			*outfile;
	char			*heredoc;
}					tp_pipe;

//execution
//builtins

void				ft_echo(char **str, int fd, char **env);
void				ft_pwd(int fd);
void				ft_exit(char **s);
void				ft_echo(char **s, int fd, char **env);
void				found(char *sa, char **env);
void				ft_cd(char **env, char **dir);
//
void				ft_errorb(char *s);
void				ft_env(char **env, char **arg, int fd);
char				**ft_envo(char **env);
void				sort_env(char **env);
void				ft_export(char **env, char **arg, int fd);
int					here(char **env, char *arg);
void				found(char *sa, char **env);
void				sort_env(char **env);
void				ft_unset(char **env, char **arg);
char				**ft_envoo(char **env,char *plus);
char				**ft_free(char **p);
#endif