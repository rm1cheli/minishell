/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:16:12 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/19 19:28:43 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	data_init(t_data *data)
{
	data->lst = NULL;
	data->env = NULL;
	data->old_pwd = NULL;
	data->res = 0;
}

void	sigin_c(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sign_d(void)
{
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("exit \n", 1);
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	signal(SIGINT, sigin_c);
	rl_replace_line("", 0);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	if (argc != 1)
		return (1);
	if (argv[0] == NULL)
		return (0);
	pars_line(env);
	return (0);
}
