/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:34:20 by houaslam          #+#    #+#             */
/*   Updated: 2023/05/08 21:42:27 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

// void	ctrl_c(int i)
// {
//     if (i == SIGINT)
//     {
//         printf("\n");
//         rl_on_new_line();
//         rl_replace_line("", 0);
//         rl_redisplay();
//     }
// }

int	main(int ac, char **av, char **en)
{
	t_data	*data;
	char	**menv;
	char	**export;

	(void)av;
	if (ac == 1)
	{
		menv = ft_envo(en);
		export = ft_envo(en);
		sort_export(export);
		data = malloc(sizeof(t_data));
		data->g_exit_status = 0;
		//signal(SIGINT, ctrl_c);
		while (1)
		{
			data->s = readline("\e[92mMINISHELL>\e[0m");
			add_history(data->s);
			if (data->s[0] != '\0' && data->s)
			{
				lexer(&data);
				if (data->g_exit_status == 0)
					transmettre(data, &menv, &export);
				free_file(&data->tmp_f);
				free_exec(&data->tmp);
				free_exec(&data->exec);
				free(data->s);
			}
		}
		ft_free(menv);
		ft_free(export);
	}
}
