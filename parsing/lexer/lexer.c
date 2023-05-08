/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:41:48 by houaslam          #+#    #+#             */
/*   Updated: 2023/05/03 20:48:13 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void	lexer(t_data **data)
{
	int		i;

	i = 0;
	(*data)->exec = NULL;
	(*data)->f = 0;
	(*data)->tmp_f = ft_lstnew_file("", IN_FILE);
	(*data)->tmp = ft_lstnew_exec("*", STRING, NULL);
	(*data)->tmp->file = NULL;
	while ((*data)->s[i])
	{
		if ((*data)->s[i] == RED_IN && (*data)->s[i + 1] == RED_IN)
			i = handle_here_doc_in(*data, i);
		else if ((*data)->s[i] == RED_OUT && (*data)->s[i + 1] == RED_OUT)
			i = handle_here_doc_out(*data, i);
		else if ((*data)->s[i] == RED_IN)
			i = handle_redin(*data, i);
		else if ((*data)->s[i] == RED_OUT)
			i = handle_redout(*data, i);
		else if ((*data)->s[i] == PIPE)
			i = handle_pipe(*data, i);
		else if ((*data)->s[i] == S_QUOT || (*data)->s[i] == D_QUOT)
			i = handle_quote(*data, i, (int)(*data)->s[i]);
		else
			i = handle_string(*data, i);
		i++;
		if ((*data)->s[i] == '\0' && (*data)->g_exit_status == 0)
		{
			ft_lstadd_back_exec(&(*data)->exec, \
			ft_lstnew_exec((*data)->tmp->value, STRING, (*data)->tmp_f));
		}
	}
	// aff1((*data)->exec, (*data)->exec->file);
}
