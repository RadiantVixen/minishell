/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:41:48 by houaslam          #+#    #+#             */
/*   Updated: 2023/06/18 00:45:18 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer_other_op(t_data **data, int i, int *singl, int *doubl)
{
	if ((*data)->s[i] == R_OUT)
		ft_lstadd_back_exec(&(*data)->lexer, \
		ft_lstnew_exec(">", R_OUT, NULL, (*data)->lexer));
	else if ((*data)->s[i] == R_IN)
		ft_lstadd_back_exec(&(*data)->lexer, \
		ft_lstnew_exec("<", R_IN, NULL, (*data)->lexer));
	else if ((*data)->s[i] == D_QUOT && (*data)->s[i + 1] == D_QUOT && ++i)
		ft_lstadd_back_exec(&(*data)->lexer, \
		ft_lstnew_exec("", EMPTY_STRING, NULL, (*data)->lexer));
	else if ((*data)->s[i] == D_QUOT && *singl % 2 == 0 && ++(*doubl))
		ft_lstadd_back_exec(&(*data)->lexer, \
		ft_lstnew_exec("\"", D_QUOT, NULL, (*data)->lexer));
	else if ((*data)->s[i] == S_QUOT && *doubl % 2 == 0 && ++(*singl))
		ft_lstadd_back_exec(&(*data)->lexer, \
		ft_lstnew_exec("\'", S_QUOT, NULL, (*data)->lexer));
	else if ((*data)->s[i] == DOLLAR)
	{
		(*data)-> d_status = *doubl;
		(*data)-> s_status = *singl;
		add(data, &i, DOLLAR);
	}
	else
		add(data, &i, STRING);
	return (i);
}

void	the_lexer(t_data **data)
{
	int	doubl;
	int	singl;
	int	i;

	i = -1;
	doubl = 0;
	singl = 0;
	while ((*data)->s[++i])
	{
		if ((*data)->s[i] == SPACE || (*data)->s[i] == TAB)
			ft_lstadd_back_exec(&(*data)->lexer, \
			ft_lstnew_exec(" ", SPACE, NULL, (*data)->lexer));
		else if ((*data)->s[i] == PIPE)
			ft_lstadd_back_exec(&(*data)->lexer, \
			ft_lstnew_exec("|", PIPE, NULL, (*data)->lexer));
		else if ((*data)->s[i] == R_IN && (*data)->s[i + 1] == R_IN && ++i)
			ft_lstadd_back_exec(&(*data)->lexer, \
			ft_lstnew_exec("<<", H_IN, NULL, (*data)->lexer));
		else if ((*data)->s[i] == R_OUT && (*data)->s[i + 1] == R_OUT && ++i)
			ft_lstadd_back_exec(&(*data)->lexer, \
			ft_lstnew_exec(">>", H_OUT, NULL, (*data)->lexer));
		else
			i = lexer_other_op(data, i, &singl, &doubl);
	}
}

void	*other_options(t_exec	*tmp, t_data	*data)
{
	if (tmp-> type == PIPE)
		tmp = handle_pipe(data, tmp);
	else if (tmp-> type == EMPTY_STRING)
		tmp = handle_empty_s(data, tmp, 0);
	else if (tmp-> type == S_QUOT)
			tmp = handle_s_quote(data, tmp, 0, 0);
	else if (tmp-> type == D_QUOT)
		tmp = handle_d_quote(data, tmp, 0, 0);
	else if (tmp-> type == STRING)
		tmp = handle_string(data, tmp, 0);
	else if (tmp-> type == DOLLAR)
		tmp = handle_dollar(data, tmp, 0, 1);
	return (tmp);
}

void	options(t_data *data)
{
	t_exec	*tmp;

	tmp = data->lexer;
	while (tmp)
	{
		if (tmp-> type == H_IN)
			tmp = handle_here_doc_in(data, tmp);
		else if (tmp-> type == H_OUT)
			tmp = handle_here_doc_out(data, tmp);
		else if (tmp-> type == R_IN)
			tmp = handle_redin(data, tmp);
		else if (tmp-> type == R_OUT)
			tmp = handle_redout(data, tmp);
		else
			tmp = other_options(tmp, data);
		if (!tmp->next && data->g_exit_status == 0)
			ft_lstadd_back_exec(&data->exec, \
			ft_lstnew_exec(data->tmp->value, STRING, data->tmp_f, tmp));
		tmp = tmp -> next;
	}
}

void	lexer(t_data **data)
{
	(*data)->g_exit_status = 0;
	(*data)->lexer = NULL;
	(*data)-> d_status = 0;
	(*data)-> s_status = 0;
	(*data)-> h_nb = 0;
	the_lexer(data);
	(*data)->exec = NULL;
	(*data)->f = 0;
	(*data)->tmp_f = NULL;
	(*data)->tmp = ft_lstnew_exec("\n", STRING, NULL, NULL);
	(*data)->tmp->file = NULL;
	(*data)->d_status = 0;
	(*data)->s_status = 0;
	if ((*data)->g_exit_status == 0)
		options(*data);
}
