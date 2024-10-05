/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:45:15 by houaslam          #+#    #+#             */
/*   Updated: 2023/06/13 14:17:15 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back_exec(t_exec **lst, t_exec *new)
{
	t_exec	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_lstlast_exec(*lst);
		last->next = new;
		new -> prev = last;
	}
	else
		*lst = new;
}

t_exec	*ft_lstnew_exec(char *value, int type, t_file *file, t_exec *curr)
{
	t_exec		*node;
	static int	which;

	node = malloc(sizeof(t_exec));
	if (!node)
		return (NULL);
	if (value)
		node->value = ft_strdup(value);
	else
		node -> value = ft_strdup("\n");
	node->type = type;
	node->file = file;
	node->next = NULL;
	if (which == 0)
		node->prev = NULL;
	else
		node->prev = curr;
	which++;
	return (node);
}

int	ft_lstsize_exec(t_exec *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_exec	*ft_lstlast_exec(t_exec *lst)
{
	t_exec	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
