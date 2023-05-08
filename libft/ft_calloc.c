/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:42:25 by houaslam          #+#    #+#             */
/*   Updated: 2023/04/02 22:13:54 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	res = malloc(sizeof(char) * (count * size));
	if (!res)
		return (NULL);
	ft_memset(res, 0, size * count);
	return (res);
}
