/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:36:44 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/18 15:49:43 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

char	**path_search_make_argv(char *av)
{
	char	**program;
	char	*tmp;

	program = NULL;
	tmp = NULL;
	program = ft_split(av, ' ');
	if (!program)
		error1(0);
	if (ft_strncmp(program[0], "export", 6) != 0
		&& ft_strncmp(program[0], "unset", 5) != 0)
		tmp = ft_strjoin("/", program[0]);
	else
		tmp = ft_strdup(program[0]);
	if (!tmp)
		error1(0);
	free(program[0]);
	program[0] = tmp;
	return (program);
}

char	**path_search_extra(char *av, char **splited_path)
{
	int		i;
	char	*tmp;
	char	**program;

	i = 0;
	tmp = NULL;
	program = path_search_make_argv(av);
	while (splited_path[i])
	{
		tmp = ft_strjoin(splited_path[i], program[0]);
		if (!tmp)
			error1(0);
		if (access(tmp, F_OK) == 0 || ft_check(program[0]) == 0)
		{
			if (ft_check(program[0]) != 0)
				path_search_ultra_extra(program, tmp);
			free(tmp);
			return (program);
		}
		free(tmp);
		i++;
	}
	printf("bash: %s: command not found\n", program[0] + 1);
	ft_free_str_arr(&program);
	return (NULL);
}

void	search1(char ***splited_av, char *cmd)
{
	*splited_av = ft_split(cmd, ' ');
	if (!*splited_av)
		error1(0);
}

void	search(char ***splited_av, char *cmd, char *env[])
{
	int		i;
	char	**splited_path;

	i = 0;
	splited_path = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", sizeof("PATH") - 1))
		{
			splited_path = ft_split(env[i] + sizeof("PATH") - 1, ':');
			if (!splited_path)
				ft_error(0);
			*splited_av = path_search_extra(cmd, splited_path);
			break ;
		}
		i++;
	}
	if (splited_path)
		ft_free_str_arr(&splited_path);
}

char	**pars_command(char *str, char **env)
{
	char	**splited_av;

	splited_av = NULL;
	if (!*str)
		return (NULL);
	if (ft_strchr1(str, '/'))
		search1(&splited_av, str);
	else
		search(&splited_av, str, env);
	return (splited_av);
}
