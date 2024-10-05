/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:49:13 by houaslam          #+#    #+#             */
/*   Updated: 2023/06/20 21:41:50 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exec	*handle_s_quote(t_data *data, t_exec *lexer, int sep, int check)
{
	data->s_status++;
	if (lexer -> next)
		lexer = lexer->next;
	if (lexer -> type == S_QUOT && check != 2)
		data->tmp->value = ft_strjoin_free(data->tmp->value, "`");
	while (lexer)
	{
		if (lexer->type == S_QUOT)
		{
			data->s_status++;
			lexer = next_case(data, lexer);
			if (sep != 1)
				data -> tmp -> value = ft_strjoin_free(data->tmp->value, "\n");
			return (lexer);
		}
		else
			data->tmp->value = ft_strjoin_free(data->tmp->value, lexer->value);
		lexer = lexer->next;
	}
	return (print_token_er(data, 258, "`\"'\n"));
}

t_exec	*handle_pipe(t_data *data, t_exec *lexer)
{
	if (check_pipe(lexer) == 1)
		return (print_token_er(data, 258, "`|'\n"));
	if (data -> tmp -> value)
	{
		ft_lstadd_back_exec(&data->exec, \
		ft_lstnew_exec(data -> tmp->value, PIPE, copy_f(data -> tmp_f), lexer));
		free_file(&data -> tmp_f);
		free_exec(&data -> tmp);
		data -> tmp = ft_lstnew_exec("\n", STRING, data -> tmp_f, lexer);
		data -> tmp_f = NULL;
	}
	return (lexer);
}

t_exec	*handle_d_quote(t_data *data, t_exec *lexer, int sep, int check)
{
	data->d_status++;
	if (lexer -> next)
		lexer = lexer->next;
	if (lexer -> type == D_QUOT && check != 2)
		data->tmp->value = ft_strjoin_free(data->tmp->value, "`");
	while (lexer)
	{
		if (lexer -> type == D_QUOT)
		{
			data->d_status++;
			lexer = next_case(data, lexer);
			if (sep != 1)
				data -> tmp -> value = ft_strjoin_free(data->tmp->value, "\n");
			return (lexer);
		}
		if (lexer->type == DOLLAR)
			lexer = handle_dollar(data, lexer, 1, 1);
		else
			data->tmp->value = ft_strjoin_free(data->tmp->value, lexer->value);
		lexer = lexer->next;
	}
	return (print_token_er(data, 258, "`\"'\n"));
}

t_exec	*handle_dollar(t_data *data, t_exec *lexer, int sep, int is_red)
{
	char	**str;
	int		k;

	str = ft_split(lexer->value, ' ');
	k = simple_while(str);
	if (k > 1)
	{
		if (is_red == 0 && (!str[0] || !str[0][0]))
			print_token_er(data, 1, " ambiguous redirect\n");
		k = -1;
		while (str[++k])
		{
			data->tmp->value = ft_strjoin_free(data->tmp->value, str[k]);
			data -> tmp -> value = ft_strjoin_free(data->tmp->value, "\n");
		}
	}
	else
		data->tmp->value = ft_strjoin_free(data->tmp->value, lexer->value);
	ft_free(str);
	if (data->d_status % 2 == 0 || data->d_status == 0)
		lexer = next_case(data, lexer);
	if (sep != 1)
		data -> tmp -> value = ft_strjoin_free(data->tmp->value, "\n");
	return (lexer);
}

t_exec	*handle_string(t_data *data, t_exec *lexer, int sep)
{
	data -> tmp -> value = ft_strjoin_free(data->tmp->value, lexer->value);
	if (lexer->next && lexer->next->type == DOLLAR)
		lexer = handle_dollar(data, lexer->next, 1, 1);
	else if (lexer->next && lexer->next->type == D_QUOT)
		lexer = handle_d_quote(data, lexer->next, 1, 2);
	else if (lexer->next && lexer->next->type == S_QUOT)
		lexer = handle_s_quote(data, lexer->next, 1, 2);
	if (lexer->next && lexer->next->type == STRING)
		lexer = handle_string(data, lexer->next, 1);
	if (sep != 1)
		data -> tmp -> value = ft_strjoin_free(data->tmp->value, "\n");
	return (lexer);
}
