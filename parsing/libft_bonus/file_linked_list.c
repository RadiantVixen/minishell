/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:45:15 by houaslam          #+#    #+#             */
/*   Updated: 2023/05/10 17:13:07 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back_file(t_file **lst, t_file *new)
{
	t_file	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_lstlast_file(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_file	*ft_lstnew_file(char *file, int type, int expand)
{
	t_file	*node;

	node = malloc(sizeof(t_file));
	if (!node)
		return (NULL);
	node->file = malloc(ft_strlen(file) + 1);
	if (!node->file)
	{
		free(node);
		return (NULL);
	}
	ft_strcpy(node->file, file);
	node->type = type;
	node->expand = expand;
	node->next = NULL;
	return (node);
}

int	ft_lstsize_file(t_file *lst)
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

t_file	*ft_lstlast_file(t_file *lst)
{
	t_file	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
