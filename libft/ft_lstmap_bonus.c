/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:49:36 by aatki             #+#    #+#             */
/*   Updated: 2022/10/23 16:05:30 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*res;

	t = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		res = ft_lstnew(f(lst->content));
		if (res == NULL)
		{
			ft_lstclear(&t, del);
			return (NULL);
		}
		ft_lstadd_back(&t, res);
		lst = lst->next;
	}
	return (t);
}
