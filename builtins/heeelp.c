/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heeelp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:33:24 by aatki             #+#    #+#             */
/*   Updated: 2023/04/17 00:33:06 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	here(char **env, char *arg)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (arg && !ft_strncmp(env[i], arg,
				ft_strlen(arg)))
			return (1);
		i++;
	}
	return (0);
}

void	found(char *sa, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], sa, ft_strlen(sa)))
			printf("%s", env[i] + ft_strlen(sa) + 1);
		i++;
	}
	return ;
}

void	sort_env(char **env)
{
	int		i;
	char	*change;

	i = 0;
	while ((env[i]))
	{
		if (env[i+1]&& ft_strncmp(env[i],env[i+1],ft_strlen(env[i]))==1)
		{
			change = ft_strdup(env[i]);
			env[i] = ft_strdup(env[i + 1]);
			env[i + 1] = ft_strdup(change);
			free(change);
			i = -1;
		}
		i++;
	}
}

char	**ft_envo(char **env)
{
	char	**menv;
	int		i;

	i = 0;
	while (env[i])
		i++;
	menv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		menv[i] = ft_strdup(env[i]);
		i++;
	}
    menv[i]=NULL;
	return (menv);
}

char **ft_envoo(char **env,char *plus)
{
	int	i;

	i = 0;
	plus=ft_strdup(plus);
	while (env[i])
		i++;
	char **menv=malloc(sizeof(char *)*(i+3));
	i=0;
	while (env[i])
	{
		menv[i] = ft_strdup(env[i]);
		i++;
	}
	if(plus)
	{
		menv[i] = plus;
		i++;
	}
    menv[i] = NULL;
	return (menv);
}


char	**ft_free(char **p)
{
	int	i;

	if (!p)
		return (NULL);
	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}