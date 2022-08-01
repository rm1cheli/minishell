/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:32:38 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/19 19:17:45 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"
#include <curses.h>
#include <term.h>

char	**_pwd_(char **env, char *str)
{
	int		i;
	char	*str2;
	char	**env2;

	env2 = copy_mas(env);
	i = 0;
	while (env2[i])
	{
		if (ft_strncmp(env[i], str, 4) == 0)
		{
			str2 = (char *)malloc(sizeof(char) * 500);
			getcwd(str2, 500);
			free(env2[i]);
			env2[i] = ft_strjoin(str, str2);
		}
		i++;
	}
	free_string1(env);
	free(str2);
	return (env2);
}

char	**old_pwd(char **env, char *str)
{
	int		i;
	bool	a;
	char	**env2;

	i = 0;
	a = 0;
	env2 = copy_mas(env);
	while (env2[i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			free(env2[i]);
			env2[i] = ft_strjoin("OLDPWD=", str);
			a = 1;
		}
		i++;
	}
	if (a != 1)
	{
		env2[i] = ft_strjoin("OLDPWD=", str);
		i++;
	}
	free_string1(env);
	return (env2);
}

char	**ft_cd(t_data *data, char **env)
{
	char	*str;

	if (ft_strlen(data->lst->cmd[0]) == 1)
		ft_putstr_fd("invalid", 1);
	str = (char *)malloc(sizeof(char) * 500);
	getcwd(str, 500);
	if (data->lst->cmd[1] == NULL)
		chdir("/Users/tconwy");
	else if (data->lst->cmd[1][0] == '-')
	{
		chdir(data->old_pwd);
	}
	else if ((chdir(data->lst->cmd[1])) != 0)
		perror ("Error");
	if (data->old_pwd)
		free(data->old_pwd);
	data->old_pwd = ft_strdup(str);
	env = old_pwd (env, str);
	env = _pwd_(env, "PWD=");
	free (str);
	return (env);
}
