/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:43:05 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/19 19:13:15 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"
#include <curses.h>
#include <term.h>

int	search_rovno(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '=')
		i++;
	return (i);
}

int	search_123(char **env, char *cmd)
{
	int		i;
	int		y;
	char	*str;

	y = 0;
	i = 0;
	str = ft_substr(cmd, 0, search_rovno(cmd));
	while (env[i])
	{
		if (ft_strncmp(env[i], str, search_rovno(env[i])) == 0)
		{
			free(str);
			return (i);
		}
		i++;
	}
	free(str);
	return (-1);
}

int	count_str_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**copy_mas(char **env)
{
	int		i;
	char	**str;

	i = count_str_env(env);
	str = (char **)malloc(sizeof(char *) * (i + 10));
	i = 0;
	while (env[i])
	{
		str[i] = ft_strdup(env[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_export(t_minilist *list, t_data *data)
{
	char	**env3;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	if (!list->cmd[1])
		sort_env(data->env);
	while (list->cmd[++i[0]])
	{
		if (correct_check(list->cmd[i[0]]) == 1)
			i[1]++;
	}
	i[2] = -1;
	i[0] = 0;
	while (data->env[i[0]])
		i[0]++;
	env3 = (char **)malloc(sizeof(char *) * (i[0] + i[1] + 1));
	while (data->env[++i[2]])
		env3[i[2]] = ft_strdup(data->env[i[2]]);
	env3 = ft_export_help(list, data, i[2], env3);
	free_string1(data->env);
	return (env3);
}
