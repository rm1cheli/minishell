/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:45:55 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/19 19:23:35 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"
#include <curses.h>
#include <term.h>

char	*ft_strjoin1(char *s1, char *s2)
{
	int		y;
	int		m;
	char	*t;

	if (s1 == NULL)
	{
		s1 = ft_strdup("\0");
	}
	t = (char *)malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 10));
	if (!t)
		return (0);
	m = 0;
	y = 0;
	while (s1[m])
		t[y++] = s1[m++];
	m = 0;
	while (s2[m])
		t[y++] = s2[m++];
	t[y] = '\0';
	free (s1);
	return (t);
}

void	ft_exit(t_minilist *lst)
{
	size_t	i;
	int		a;

	i = 0;
	if (lst->cmd[1] != NULL)
	{
		while (ft_isdigit(lst->cmd[1][i]))
			i++;
		if (ft_strlen(lst->cmd[1]) != i)
		{
			ft_putstr_fd("bash: exit: qwe: numeric argument required\n", 1);
			exit(255);
		}
		a = ft_atoi(lst->cmd[1]);
		exit(a);
	}
	exit(0);
}

int	commands2(t_data *data, t_minilist *lst)
{
	int	i;

	i = 0;
	if (ft_strncmp(lst->cmd[0], "export", 6) == 0)
		data->env = ft_export(lst, data);
	else if (++i && (ft_strncmp(data->lst->cmd[0], "/usr/bin/cd", 11) == 0
			|| ft_strncmp(data->lst->cmd[0], "cd", 2) == 0))
		data->env = ft_cd(data, data->env);
	else if (++i && ft_strncmp(lst->cmd[0], "unset", 5) == 0)
		data->env = ft_unset(lst, data->env);
	else if (++i && ft_strncmp(lst->cmd[0], "/usr/bin/env", 12) == 0)
		ft_env(data->env);
	else if (++i && (ft_strncmp(lst->cmd[0], "echo", 9) == 0
			|| ft_strncmp(lst->cmd[0], "/bin/echo", 1000) == 0))
		ft_echo(data->lst);
	else if (++i && ft_strncmp(lst->cmd[0], "/bin/pwd", 8) == 0)
		ft_pwd();
	else if (++i && ft_strncmp(lst->cmd[0], "/exit", 5) == 0)
		ft_exit(data->lst);
	else
		++i;
	if (i < 7)
		return (0);
	return (1);
}

void	commands(t_data *data, t_minilist *lst)
{
	pid_t	pid;

	while (lst)
	{
		if (lst->type == 0)
		{
			data->env = change_(data->env, lst);
			if (commands2(data, lst) == 1)
			{
				pid = fork();
				if (lst->fd[0] != -1 || lst->fd[1] != -1)
					execve_red(lst);
				if (pid == 0)
				{
					execve (lst->cmd[0], lst->cmd, data->env);
					perror ("Execve error");
					exit(1);
				}
			}
		}
		lst = lst->next;
	}
}

int	ft_check(char *tmp)
{
	if ((ft_strncmp(tmp, "export", 6) == 0)
		|| (ft_strncmp(tmp, "unset", 5) == 0)
		|| (ft_strncmp(tmp, "/exit", 5) == 0))
		return (0);
	else
		return (1);
}
