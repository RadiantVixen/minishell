/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:34:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/06/21 00:27:03 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

void	ctrl_c(int i)
{
	if (i == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = 1;
	}
}

void	the_while(t_data *data, char **menv, char **export)
{
	(void)export;
	while (1)
	{
		data->s = readline("MINISHELL>");
		add_history(data->s);
		if (!data->s)
		{
			printf("exit\n");
			exit(0);
		}
		if (data->s[0] != '\0' && data->s)
		{
			lexer(&data);
			if (data->g_exit_status == 0)
				transmettre(data, &menv, &export);
			signal(SIGINT, ctrl_c);
			free_file(&data->tmp_f);
			free_exec(&data->tmp);
			free_exec(&data->exec);
			free_exec(&data->lexer);
			free(data->s);
			data->env = menv;
		}
	}
}

int	main(int ac, char **av, char **en)
{
	t_data	*data;
	char	**menv;
	char	**export;

	(void)av;
	if (ac == 1)
	{
		g_exit_status = 0;
		menv = ft_envo(en);
		export = ft_envo(en);
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		sort_export(export);
		data = malloc(sizeof(t_data));
		data->env = menv;
		the_while(data, menv, export);
		ft_free(menv);
		ft_free(export);
	}
}
