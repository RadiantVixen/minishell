/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:49:13 by houaslam          #+#    #+#             */
/*   Updated: 2023/05/04 18:42:00 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_string(t_data *data, int i)
{
	int		k;
	char	*res;
	char	*str;

	str = NULL;
	k = i;
	while (data->s[i] && ft_isstring(data->s[i]))
		i++;
	res = ft_substr(data->s, k, i - k);
	str = ft_strjoin(str, res);
	data -> tmp->value = ft_strjoin_free(data -> tmp->value, str);
	free(str);
	free(res);
	if (data->s[i] && (data->s[i] == \
	D_QUOT || data->s[i] == S_QUOT))
		i = handle_quote(data, i, (int)data->s[i]);
	if (!ft_isstring_w_s(data->s[i]))
		return (i - 1);
	data -> tmp->value = ft_strjoin_free(data -> tmp->value, "*");
	return (i);
}

int	handle_quote(t_data *data, int i, int type)
{
	int		k;
	char	*res;

	i++;
	k = i;
	while (data->s[i] != type)
	{
		if (data->s[i] == '\0')
			return (print_token_er(data, 1, data -> tmp));
		if (data->s[i] == '$')
			k = handle_dollar(data, i, k);
		i++;
	}
	res = ft_substr(data->s, k, i - k);
	data -> tmp->value = ft_strjoin_free(data -> tmp->value, res);
	free(res);
	i++;
	if (ft_isstring(data->s[i]) && data->s[i])
		i = handle_string(data, i);
	data -> tmp->value = ft_strjoin_free(data -> tmp -> value, "*");
	return (i);
}

int	check_pipe(t_data *data, int i)
{
	int		k;
	int		c;

	k = i + 1;
	c = i - 1;
	if (c < 0 || k >= (int)ft_strlen(data->s))
		return (1);
	while (data->s[c])
	{
		if (ft_isalpha(data->s[c]))
			break ;
		if (c == 0)
			return (1);
		c--;
	}
	while (data->s[k])
	{
		if (ft_isstring(data->s[k]))
			break ;
		if (data->s[k] == '\0')
			return (1);
		k++;
	}
	return (0);
}

int	handle_pipe(t_data *data, int i)
{
	if (check_pipe(data, i) == 1)
		return (print_token_er(data, 258, data -> tmp));
	if (data -> tmp -> value)
	{
		ft_lstadd_back_exec(&data->exec, \
		ft_lstnew_exec(data -> tmp->value, PIPE, data -> tmp_f));
		free_exec(&data -> tmp);
		data -> tmp = ft_lstnew_exec("*", STRING, data -> tmp_f);
	}
	return (i);
}
