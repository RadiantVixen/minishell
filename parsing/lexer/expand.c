/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:51:22 by houaslam          #+#    #+#             */
/*   Updated: 2023/06/17 16:26:27 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exec	*handle_empty_s(t_data *data, t_exec *lexer, int sep)
{
	if (lexer->next && lexer->prev && (lexer->next->type == SPACE \
	|| lexer->next->type == TAB) \
	&& (lexer->prev->type == SPACE || lexer->prev->type == TAB))
	{
		data -> tmp -> value = ft_strjoin_free(data->tmp->value, "`");
		data -> tmp -> value = ft_strjoin_free(data->tmp->value, "\n");
	}
	else if (!lexer->next && lexer->prev && \
	(lexer->prev->type == SPACE || lexer->prev->type == TAB))
	{
		data -> tmp -> value = ft_strjoin_free(data->tmp->value, "`");
		data -> tmp -> value = ft_strjoin_free(data->tmp->value, "\n");
	}
	else if (!lexer->next && !lexer->prev)
	{
		data -> tmp -> value = ft_strjoin_free(data->tmp->value, "`");
		data -> tmp -> value = ft_strjoin_free(data->tmp->value, "\n");
	}
	else
		lexer = next_case(data, lexer);
	if (sep != 1)
		data -> tmp -> value = ft_strjoin_free(data->tmp->value, "\n");
	return (lexer);
}

char	*expande_handle(t_data *data, char *str)
{
	char	*save;
	char	*ptr;

	if (data -> d_status % 2 == 0 && data -> s_status % 2 != 0)
		return (str);
	else
	{
		ptr = ft_substr(str, 1, ft_strlen(str) - 1);
		save = find_ex(ptr, data->env);
		free(ptr);
		free(str);
	}
	return (save);
}

char	*the_expande(t_data *data, char *str)
{
	char	*save;
	char	*ptr;

	if (str[1] == '?')
	{
		ptr = ft_substr(str, 2, ft_strlen(str) - 2);
		save = ft_itoa(g_exit_status);
		save = ft_strjoin_free(save, ptr);
		free(str);
		free(ptr);
		return (save);
	}
	else if (ft_isdigit(str[1]))
	{
		save = ft_substr(str, 2, ft_strlen(str) - 2);
		free(str);
		return (save);
	}
	else if (!str[1])
		return (ft_strdup("$"));
	else
		return (expande_handle(data, str));
	return (str);
}

t_exec	*next_case(t_data *data, t_exec *lexer)
{
	if (lexer->next && lexer->next->type == EMPTY_STRING)
		lexer = lexer->next;
	else if (lexer->next && lexer->next->type == DOLLAR)
		lexer = handle_dollar(data, lexer->next, 1, 1);
	else if (lexer->next && lexer->next->type == D_QUOT)
		lexer = handle_d_quote(data, lexer->next, 1, 2);
	else if (lexer->next && lexer->next->type == S_QUOT)
		lexer = handle_s_quote(data, lexer->next, 1, 2);
	else if (lexer->next && lexer->next->type == STRING)
		lexer = handle_string(data, lexer->next, 1);
	return (lexer);
}

int	check_pipe(t_exec *lexer)
{
	t_exec	*tmp;

	tmp = lexer;
	while (tmp)
	{
		if (tmp->type == STRING || tmp->type == DOLLAR)
			break ;
		if ((tmp->prev == NULL || tmp->prev->type == PIPE))
			return (1);
		tmp = tmp->prev;
	}
	tmp = lexer;
	while (tmp)
	{
		if (tmp->type == STRING || tmp->type == DOLLAR)
			break ;
		if ((tmp->next == NULL || tmp->next->type == PIPE))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
