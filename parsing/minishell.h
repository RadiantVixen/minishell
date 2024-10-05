/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:32:03 by houaslam          #+#    #+#             */
/*   Updated: 2023/06/18 00:45:53 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PIPE  124 //
# define SPACE  32 //
# define R_IN  60 //
# define R_OUT  62 //
# define D_QUOT  34 ///
# define S_QUOT  39 ///
# define IN_FILE 2
# define STRING 1 
# define EMPTY_STRING 2 
# define TAB 9
# define OUT_FILE 3
# define H_IN 5 //
# define H_OUT 6 //
# define EXIT_STATUS 7
# define DOLLAR 36 

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
	int				expand;
	char			*file;
	struct s_file	*next;
}			t_file;

typedef struct exec
{
	int			type;
	char		*value;
	char		**cmd;
	int			expand;
	t_file		*file;
	struct exec	*next;
	struct exec	*prev;
}			t_exec;

typedef struct s_data
{
	int			g_exit_status;
	int			pipe;
	char		**env;
	int			d_status;
	int			s_status;
	t_exec		*tmp;
	t_file		*tmp_f;
	t_exec		*exec;
	t_exec		*lexer;
	int			f;
	int			h_nb;
	char		*s;
}			t_data;

// linked list
void		ft_lstadd_back(t_env **lst, t_env *new);
t_env		*ft_lstnew(char *name, char *path);
int			ft_lstsize(t_env *lst);
t_env		*ft_lstlast(t_env *lst);

// linked list exec
void		ft_lstadd_back_exec(t_exec **lst, t_exec *new);
t_exec		*ft_lstnew_exec(char *value, int type, t_file *file, t_exec *curr);
int			ft_lstsize_exec(t_exec *lst);
t_exec		*ft_lstlast_exec(t_exec *lst);
void		free_exec(t_exec **exec);

// linked list file
void		ft_lstadd_back_file(t_file **lst, t_file *new);
t_file		*ft_lstnew_file(char *value, int typem, int expand);
int			ft_lstsize_file(t_file *lst);
t_file		*ft_lstlast_file(t_file *lst);
void		free_file(t_file **file);
t_file		*copy_f(t_file *file);

//env
void		creat_env(char **en, t_data **data);
void		aff(t_env *env);
void		aff1(t_exec *env, t_file *file);
void		aff2(t_file *env);

extern void	rl_replace_line(const char *str, int n);

//spec char tokens
void		lexer(t_data **data);
t_exec		*handle_redin(t_data *data, t_exec *lexer);
t_exec		*handle_redout(t_data *data, t_exec *lexer);
t_exec		*handle_here_doc_in(t_data *data, t_exec *lexer);
t_exec		*handle_here_doc_out(t_data *data, t_exec *lexer);
int			check_pipe(t_exec *lexer);

//string tokens
t_exec		*handle_pipe(t_data *data, t_exec *lexer);
t_exec		*handle_string(t_data *data, t_exec *lexer, int sep);
t_exec		*handle_s_quote(t_data *data, t_exec *lexer, int sep, int check);
t_exec		*handle_d_quote(t_data *data, t_exec *lexer, int sep, int check);
t_exec		*handle_dollar(t_data *data, t_exec *lexer, int sep, int is_red);
t_exec		*handle_empty_s(t_data *data, t_exec *lexer, int sep);

//outils
char		*find_ex(char *sa, char **env);
char		*seach_env_value(char *str, t_data *data);
t_exec		*print_token_er(t_data *data, int status, char *s1);
int			ft_isstring(char c);
int			ft_isstring_w_s(char c);
int			ft_isstring_w_q(char c);
void		transmettre(t_data *data, char ***env, char ***export);
void		add(t_data **data, int *i, int type);
char		*the_expande(t_data *data, char *str);
char		*expande_handle(t_data *data, char *str);
t_exec		*next_case(t_data *data, t_exec *lexer);
int			simple_while(char **str);
int			dollar(t_data *data, t_exec *lexer, int is_red);
void		ctrl_c(int i);
void		for_norm_(char ***export, char ***env, char **arg, char **sp);

#endif