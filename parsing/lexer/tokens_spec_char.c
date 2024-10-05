/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_spec_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:56:12 by houaslam          #+#    #+#             */
/*   Updated: 2023/06/18 00:45:42 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exec	*handle_here_doc_in2(t_data *data, t_exec *lexer, int *nb)
{
	char	*str;

	if (lexer ->type == STRING)
	{
		ft_lstadd_back_file(&data -> tmp_f, ft_lstnew_file \
		(lexer->value, H_IN, 0));
		(*nb)++;
	}
	else if ((lexer ->type == S_QUOT || lexer ->type == D_QUOT))
	{
		lexer = lexer->next;
		str = ft_substr(lexer->value, 0, ft_strlen(lexer->value));
		ft_lstadd_back_file(&data -> tmp_f, ft_lstnew_file \
		(str, H_IN, 1));
		lexer = lexer->next;
		(*nb)++;
	}
	else if (lexer->type == DOLLAR)
	{
		lexer = handle_dollar(data, lexer, 1, 0);
		(*nb)++;
	}
	else
		return (print_token_er(data, 258, "`<<'\n"));
	return (lexer);
}

t_exec	*handle_here_doc_in(t_data *data, t_exec *lexer)
{
	if (lexer -> next)
		lexer = lexer->next;
	while (lexer && (lexer->type == SPACE || lexer->type == TAB))
		lexer = lexer->next;
	if (!lexer)
		return (print_token_er(data, 258, "`<<'\n"));
	else
		lexer = handle_here_doc_in2(data, lexer, &data->h_nb);
	if (data->h_nb > 16)
	{
		ft_errorb("bash: ", "maximum here-document count exceeded\n", NULL, 2);
		exit(2);
	}
	return (lexer);
}

t_exec	*handle_here_doc_out(t_data *data, t_exec *lexer)
{
	char	*str;

	if (lexer -> next)
		lexer = lexer->next;
	while (lexer && (lexer->type == SPACE || lexer->type == TAB))
		lexer = lexer->next;
	if (!lexer)
		return (print_token_er(data, 258, "`newline'\n"));
	else if (lexer ->type == STRING)
		ft_lstadd_back_file(&data -> tmp_f, ft_lstnew_file \
		(lexer->value, H_OUT, 0));
	else if (lexer ->type == S_QUOT || lexer ->type == D_QUOT)
	{
		str = ft_substr(lexer->value, 1, ft_strlen(lexer->value) - 1);
		ft_lstadd_back_file(&data -> tmp_f, \
		ft_lstnew_file(str, H_OUT, 1));
	}
	else if (lexer->type == DOLLAR)
		lexer = handle_dollar(data, lexer, 1, 0);
	else
		return (print_token_er(data, 258, "`>>'\n"));
	return (lexer);
}

t_exec	*handle_redout(t_data *data, t_exec *lexer)
{
	char	*str;

	if (lexer -> next)
		lexer = lexer->next;
	while (lexer && (lexer->type == SPACE || lexer->type == TAB))
		lexer = lexer->next;
	if (!lexer)
		return (print_token_er(data, 258, "`>'\n"));
	else if (lexer && lexer -> type == STRING)
	{
		ft_lstadd_back_file(&data -> tmp_f, \
		ft_lstnew_file(lexer->value, R_OUT, 0));
	}
	else if (lexer && (lexer ->type == S_QUOT || lexer ->type == D_QUOT))
	{
		str = ft_substr(lexer->value, 1, \
		ft_strlen(lexer->value) - 1);
		ft_lstadd_back_file(&data -> tmp_f, ft_lstnew_file(str, R_OUT, 0));
	}
	else if (lexer->type == DOLLAR)
		lexer = handle_dollar(data, lexer, 1, 0);
	else
		return (print_token_er(data, 258, "`>'\n"));
	return (lexer);
}

t_exec	*handle_redin(t_data *data, t_exec *lexer)
{
	char	*str;

	if (lexer -> next)
		lexer = lexer->next;
	while (lexer && (lexer->type == SPACE || lexer->type == TAB))
		lexer = lexer->next;
	if (!lexer)
		return (print_token_er(data, 258, "`<'\n"));
	if (lexer ->type == STRING)
	{
		ft_lstadd_back_file(&data -> tmp_f, \
		ft_lstnew_file(lexer->value, R_IN, 0));
	}
	else if (lexer ->type == S_QUOT || lexer ->type == D_QUOT)
	{
		str = ft_substr(lexer->value, 1, \
		ft_strlen(lexer->value) - 1);
		ft_lstadd_back_file(&data -> tmp_f, ft_lstnew_file(str, R_IN, 0));
	}
	else if (lexer->type == DOLLAR)
		lexer = handle_dollar(data, lexer, 1, 0);
	else
		return (print_token_er(data, 258, "`<'\n"));
	return (lexer);
}
