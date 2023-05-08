/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:32:03 by houaslam          #+#    #+#             */
/*   Updated: 2023/05/08 14:18:09 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PIPE  124
# define RED_IN  60
# define RED_OUT  62
# define D_QUOT  34
# define S_QUOT  39
# define IN_FILE 2
# define STRING 1
# define BUILTIN 4
# define OUT_FILE 3
# define HERE_DOC_IN 5
# define HERE_DOC_OUT 6
# define EXIT_STATUS 7
# define ENV_VAR 8

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include <signal.h>
# include<string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include"../libft/libft.h"
# include "../executionn/builtins/builtins.h"
# include "../executionn/pipex/pipex_bonus.h"

typedef struct env
{
	char		*path;
	char		*name;
	struct env	*next;
}			t_env;

typedef struct s_file
{
	int				type;
	char			*file;
	struct s_file	*next;
}			t_file;

typedef struct exec
{
	int			type;
	char		*value;
	t_file		*file;
	struct exec	*next;
}			t_exec;

typedef struct s_data
{
	int			g_exit_status;
	int			pipe;
	t_exec		*tmp;
	t_file		*tmp_f;
	t_env		*env;
	t_exec		*exec;
	int			f;
	char		*s;
}			t_data;

// linked list
void	ft_lstadd_back(t_env **lst, t_env *new);
t_env	*ft_lstnew(char *name, char *path);
int		ft_lstsize(t_env *lst);
t_env	*ft_lstlast(t_env *lst);

// linked list
void	ft_lstadd_back_exec(t_exec **lst, t_exec *new);
t_exec	*ft_lstnew_exec(char *value, int type, t_file *file);
int		ft_lstsize_exec(t_exec *lst);
t_exec	*ft_lstlast_exec(t_exec *lst);
void	free_exec(t_exec **exec);

// linked list
void	ft_lstadd_back_file(t_file **lst, t_file *new);
t_file	*ft_lstnew_file(char *value, int type);
int		ft_lstsize_file(t_file *lst);
t_file	*ft_lstlast_file(t_file *lst);
void	free_file(t_file **file);

//env
void	creat_env(char **en, t_data **data);
void	aff(t_env *env);
void	aff1(t_exec *env, t_file *file);
void	aff2(t_file *env);

//spec char tokens
void	lexer(t_data **data);
int		handle_redin(t_data *data, int i);
int		handle_redout(t_data *data, int i);
int		handle_here_doc_in(t_data *data, int i);
int		handle_here_doc_out(t_data *data, int i);
int		chek_pipe(t_data *data, int i);

//string tokens
int		handle_pipe(t_data *data, int i);
int		handle_string(t_data *data, int i);
int		handle_quote(t_data *data, int i, int type);
int		handle_dollar(t_data *data, int i, int k);
int		handle_env_var(t_data *data, int i, int k);

//outils
char	*seach_env_value(char *str, t_data *data);
int		print_token_er(t_data *data, int i, t_exec *tmp);
int		ft_isstring(char c);
int		ft_isstring_w_s(char c);
int		ft_isstring_w_q(char c);
void	transmettre(t_data *data, char ***env, char ***export);

#endif