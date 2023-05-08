/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_spec_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:56:12 by houaslam          #+#    #+#             */
/*   Updated: 2023/05/08 14:32:32 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_here_doc_in(t_data *data, int i)
{
	int		k;
	char	*str;

	i += 2;
	while (data->s[i] == 32 || data->s[i] == 9)
		i++;
	k = i;
	while (data->s[i] && ft_isstring(data->s[i]))
		i++;
	str = ft_substr(data->s, k, i - k);
	if (str[0] == '\0' || i - k == 0)
	{
		free(str);
		return (print_token_er(data, 1, NULL));
	}
	if (data->f == 0)
	{
		data -> tmp_f->file = ft_strjoin_free(data -> tmp_f->file, str);
		data -> tmp_f->type = HERE_DOC_IN;
		data->f = 1;
	}
	else
		ft_lstadd_back_file(&data -> tmp_f, ft_lstnew_file(str, HERE_DOC_IN));
	free(str);
	return (i);
}

int	handle_here_doc_out(t_data *data, int i)
{
	int		k;
	char	*str;

	i += 2;
	while (data->s[i] == 32 || data->s[i] == 9)
		i++;
	k = i;
	while (data->s[i] && ft_isstring(data->s[i]))
		i++;
	str = ft_substr(data->s, k, i - k);
	if (str[0] == '\0' || i - k == 0)
	{
		free(str);
		return (print_token_er(data, 1, NULL));
	}
	if (data->f == 0)
	{
		data -> tmp_f->file = ft_strjoin_free(data -> tmp_f->file, str);
		data -> tmp_f->type = HERE_DOC_OUT;
		data->f = 1;
	}
	else
		ft_lstadd_back_file(&data -> tmp_f, ft_lstnew_file(str, HERE_DOC_OUT));
	free(str);
	return (i);
}

int	handle_redin(t_data *data, int i)
{
	int		k;
	char	*str;

	i++;
	while (data->s[i] == 32 || data->s[i] == 9)
		i++;
	k = i;
	while (data->s[i] && ft_isstring(data->s[i]))
		i++;
	str = ft_substr(data->s, k, i - k);
	if (str[0] == '\0' || i - k == 0)
	{
		free(str);
		return (print_token_er(data, 1, NULL));
	}
	if (data->f == 0)
	{
		data -> tmp_f->file = ft_strjoin_free(data -> tmp_f->file, str);
		data -> tmp_f->type = RED_IN;
		data->f = 1;
	}
	else
		ft_lstadd_back_file(&data -> tmp_f, ft_lstnew_file(str, RED_IN));
	free(str);
	return (i - 1);
}

int	handle_redout(t_data *data, int i)
{
	int		k;
	char	*str;

	i++;
	while (data->s[i] == 32 || data->s[i] == 9)
		i++;
	k = i;
	while (data->s[i] && ft_isstring(data->s[i]))
		i++;
	str = ft_substr(data->s, k, i - k);
	if (str[0] == '\0' || i - k == 0)
	{
		free(str);
		return (print_token_er(data, 1, NULL));
	}
	if (data->f == 0)
	{
		data -> tmp_f->file = ft_strjoin_free(data -> tmp_f->file, str);
		data -> tmp_f->type = RED_OUT;
		data->f = 1;
	}
	else
		ft_lstadd_back_file(&data -> tmp_f, ft_lstnew_file(str, RED_OUT));
	free(str);
	return (i - 1);
}

int	handle_dollar(t_data *data, int i, int k)
{
	char	*res;

	res = ft_substr(data->s, k, i - k);
	data -> tmp->value = ft_strjoin_free(data -> tmp->value, res);
	data -> tmp->value = ft_strjoin_free(data -> tmp->value, "*");
	data -> tmp->value = ft_strjoin_free(data -> tmp->value, "$");
	data -> tmp->value = ft_strjoin_free(data -> tmp->value, "*");
	k = i + 1;
	return (k);
}
