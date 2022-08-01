/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:43:53 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/16 17:30:08 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"
#include <curses.h>
#include <term.h>
#include <signal.h>

void	execve_red(t_minilist *list)
{
	if (list->fd[0] != -1)
	{
		dup2(list->fd[0], 0);
		close(list->fd[0]);
	}
	if (list->fd[1] != -1)
	{
		dup2(list->fd[1], 1);
		close(list->fd[1]);
	}
}

void	pipe_mini_help(t_data *data, int *pipefd, pid_t pid)
{
	while (data->lst)
	{
		pipe(pipefd);
		pid = fork();
		if (pid == 0)
		{
			close(pipefd[0]);
			if (data->lst->type == 1)
				dup2(pipefd[1], 1);
			if (data->lst->fd[0] != -1 || data->lst->fd[1] != -1)
				execve_red(data->lst);
			if (commands2(data, data->lst) == 1)
				execve(data->lst->cmd[0], data->lst->cmd, data->env);
			exit(0);
		}
		else
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			close(pipefd[0]);
		}
		if (!data->lst->next || data->lst->type == 2)
			break ;
		data->lst = data->lst->next;
	}
}

void	pipe_mini(t_data *data)
{
	pid_t	pid;
	int		pipefd[2];

	pid = 0;
	pipe_mini_help(data, pipefd, pid);
	data->lst = data->lst->next;
}
