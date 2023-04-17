/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:01:17 by aatki             #+#    #+#             */
/*   Updated: 2023/03/06 19:10:29 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	init_get_next_line(char **string, char **tmp_string, char **tmp, char **s)
{
	*string = NULL;
	*tmp_string = NULL;
	*tmp = NULL;
	if (*s)
	{
		*string = ft_strjoin(*string, *s);
		free(*s);
		*s = NULL;
	}
	*tmp = malloc(BUFFER_SIZE + 1);
	if (!*tmp)
	{
		free(*string);
		return (0);
	}
	return (1);
}

char	*end_get_next_line(char **tmp, char **s, char **string)
{
	free(*tmp);
	*s = check(string);
	if (*string[0] == '\0')
	{
		free(*string);
		*string = NULL;
		free(*s);
		*s = NULL;
	}
	return (*string);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*string;
	char		*tmp;
	int			readed;
	char		*tmp_string;

	if (fd < 0 || BUFFER_SIZE <= 0 || !init_get_next_line(&string, &tmp_string,
			&tmp, &s))
		return (NULL);
	readed = 1;
	while (new_line(string) && readed)
	{
		readed = read(fd, tmp, BUFFER_SIZE);
		if (readed == -1)
		{
			free(tmp);
			free(string);
			return (0);
		}
		tmp[readed] = '\0';
		string = ft_strjoin(string, tmp);
	}
	return (end_get_next_line(&tmp, &s, &string));
}
