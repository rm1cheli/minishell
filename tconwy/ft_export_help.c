/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:41:28 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/19 19:13:15 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

char	**ft_export_help(t_minilist *list, t_data *data, int a, char **env3)
{
	int	i[2];

	i[0] = 1;
	while (list->cmd[i[0]])
	{
		i[1] = search_123(data->env, list->cmd[i[0]]);
		if (i[1] != -1)
		{
			if (env3[i[1]])
				free(env3[i[1]]);
			if (correct_check(list->cmd[i[0]]) == 1)
				env3[i[1]] = ft_strdup(list->cmd[i[0]]);
		}
		else
		{
			if (list->cmd[i[0]][0] == '=')
				printf("bash: export: '%s': not a valid identifier\n",
					list->cmd[i[0]]);
			else if (correct_check(list->cmd[i[0]]) == 1)
				env3[a++] = ft_strdup(list->cmd[i[0]]);
		}
		i[0]++;
	}
	env3[a] = NULL;
	return (env3);
}

int	who_is_more(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

int	correct_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (-1);
		i++;
	}
	if (str[i] == '=' && i == 0)
		return (-1);
	return (1);
}

void	sort_env(char **env)
{
	int		size[2];
	char	*str;
	char	**str2;

	size[0] = count_str_env(env);
	str2 = copy_mas(env);
	while (size[0] >= 0)
	{
		size[1] = count_str_env(env);
		while (size[1] >= 0)
		{
			if (who_is_more (str2[size[0]], str2[size[1]]) > 0)
			{
				str = ft_strdup(str2[size[0]]);
				free(str2[size[0]]);
				str2[size[0]] = ft_strdup(str2[size[1]]);
				free(str2[size[1]]);
				str2[size[1]] = ft_strdup(str);
				free(str);
			}
			size[1]--;
		}
		size[0]--;
	}
	export_printf(str2);
}
