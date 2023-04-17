/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:37:52 by aatki             #+#    #+#             */
/*   Updated: 2023/04/17 00:27:37 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_cd(char **env, char **dir)
{
	int	i;
	char	buff[1024];

	// i = 0;
	// if (!getcwd(buff, 1024))
	// 	ft_error("no path");
	// while (env[i])
	// {
	// 	if(!ft_strncmp(env[i],"PWD=",4))
	// 	{
	// 		env[i]=ft_strjoin("PWD=",dir);
	// 		printf("%s\n", env[i]);
	// 	}
	// 	if(!ft_strncmp(env[i],"OLDPWD=",7))
	// 	{
	// 		env[i]=ft_strjoin("OLDPWD=",buff);
	// 		printf("%s\n", env[i]);
	// 	}
	// 	i++;
	// }
	//ft_env(env,1);
}

void	ft_echo(char **s, int fd, char **env)
{
	int	i;

	dup2(fd, 1);
	i = 2;
	if (!ft_strncmp(s[0], "-n", 2))
		i++;
	while (s[i])
	{
		if (s[i][0] == '$')
		{
			if (s[i][1] == '\'' || s[i][1] == '\"')
				printf("%s", s[i] + 2);
			else
				found(s[i] + 1, env);
		}
		else
			printf("!!!!%s!!!!!", s[i]);
		i++;
		printf(" ");
	}
	if (ft_strncmp(s[0], "-n", 2))
		printf("\n");
}

void	ft_exit(char **arg)
{
	
}
