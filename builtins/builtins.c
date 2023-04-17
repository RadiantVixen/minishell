/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 05:24:12 by aatki             #+#    #+#             */
/*   Updated: 2023/04/17 00:57:02 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	**equal(char *s, char c)
{
	char	**sp;
	int		i;

	if(!s)
		return NULL;
	sp = malloc(sizeof(char *) * 2);
	i = 0;
	sp[0] = malloc(ft_strlen(s)+1);
	sp[0][ft_strlen(s)]='\0';
	while (s[i])
	{
		sp[0][i] = s[i];
		if (s[i] == '=')
		{
			sp[0][i + 1] = '\0';
			// free(sp[0]+i+2);
			break ;
		}
		i++;
	}
	sp[1] = ft_strchr(s, c) + 1;
	return (sp);
}

// int	exist(char **env,char *s)
// {
// 	int i=0;
	
// 	while(env[i])
// 	{
		
// 	}
// }

void	ft_export(char **env, char **arg, int fd)
{
// 	int		i;
// 	char	**export;
// 	char	**sp;
// 	char	**sp2;

// 	i = 0;
// 	int k=0;
// 	int j=0;
	
// 	if(*arg)
// 	{
// 		while(arg[k])
// 		{
// 				sp = equal(arg[k], '=');
// 			if(sp[0][0]=='$')
// 			{
// 				j=1;
// 				sp[0]+=1;
// 				arg[k]+=1;
// 			}
// 			if(here(env,sp[0]))
// 			{
// 				if(j==1)
// 					ft_error("noooo");
// 				else
// 				{
// 					if(sp[0][ft_strlen(sp[0])]=='=')
// 						return;
// 					else
// 					{
// 						ft_unset(env,sp[0]);
// 						export = ft_envoo(env,arg[k]);
// 						//ft_free(env);
// 						env=ft_envoo(export,NULL);
// 					}
// 				}
// 			}
// 			else
// 			{
// 				if(sp[0][ft_strlen(sp[0])]=='=')
// 				{
// 					if(j==1)
// 						ft_error("noooo");
// 					else
// 					{
// 						export = ft_envoo(env,arg[k]);
// 						//ft_free(env);
// 						env=ft_envoo(export,NULL);
// 					}
// 				}
// 				else
// 				{
// 					if(j==1)
// 						return;
// 					else
// 						export = ft_envoo(env,arg[k]);
// 				}
// 			}
// 			k++;
// 		}
// 		ft_env(export,NULL,1);
// 	}
// 	else
// 	{
// 		export = ft_envoo(env,arg);
// 		sort_env(export);
// 		dup2(fd, 1);
// 		// ft_env(env,NULL,1);
// 		// exit(0);
// 		while (export[i])
// 		{
// 			sp2 = equal(export[i], '=');
// 			printf("declare -x %s\"%s\"\n", sp2[0], sp2[1]);
// 			free(sp2[0]);
// 			free(sp2);
// 			i++;
// 		}
// 	}
}

void	ft_env(char **env, char **arg, int fd)
{
	int		i;
	char	**sp;


	dup2(fd, 1);
	int j=0;
	while(arg[j])
	{
		i=0;
		if (arg[j])
			sp = equal(arg[j], '=');
		if (arg[j] && !here(env, sp[0]))
			ft_errorb("No such file or directory");
		while (env[i])
		{
			if (arg[j] && here(env, sp[0]) && !ft_strncmp(env[i], sp[0],
					ft_strlen(sp[0])))
			{
				printf("%s\n", arg[j]);
				i++;
			}
			printf("%s\n", env[i]);
			i++;
		}
		ft_free(sp);
		j++;
	}
}

void	ft_pwd(int fd)
{
	char	buff[1024];

	dup2(fd, 1);
	if (getcwd(buff, 1024))
		printf("%s\n", buff);
	else
		ft_errorb("no path");
}

void	ft_unset(char **env, char **arg)
{
	int	i;

	int j=0;
	while(arg[j])
	{
		i=0;
		while ((env[i]))
		{
			if (arg && !ft_strncmp(env[i], arg[j], ft_strlen(arg[j])))
				break ;
			i++;
		}
		if (!env[i])
			return ;
		while ((env[i + 1]))
		{
			printf("vjkfdbh\n");
			//free(env[i]);
			env[i] = ft_strdup(env[i + 1]);
			i++;
		}
		env[i] = NULL;
		j++;
	}
	
	ft_env(env, NULL, 1);
}
