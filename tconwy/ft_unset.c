/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:32:51 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/19 19:00:28 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"
#include <curses.h>
#include <term.h>

void	free_string1(char **u)
{
	int	y;

	y = 0;
	while (u[y])
	{
		free(u[y++]);
	}
	free(u);
}

char	**unset_arg(char **env2, int i)
{
	char	**env3;
	int		a[2];

	a[0] = 0;
	a[1] = 0;
	while (env2[a[0]])
		a[0]++;
	env3 = (char **)malloc(sizeof(char *) * (a[0] + 1));
	a[0] = 0;
	while (env2[a[0]])
	{
		if (a[0] == i)
			a[0]++;
		if (env2[a[0]] == NULL)
		{
			free_string1(env2);
			return (env3);
		}
		if (env2[a[0]])
			env3[a[1]] = ft_strdup(env2[a[0]]);
		a[0]++;
		a[1]++;
	}
	free_string1(env2);
	return (env3);
}

char	**ft_unset(t_minilist *list, char **env)
{
	char	**env2;
	int		i;
	int		a;
	int		y;

	a = 1;
	i = 0;
	y = 0;
	env2 = copy_mas (env);
	while (list->cmd[a])
	{
		while (env2[i])
		{
			if (ft_strncmp(env2[i], list->cmd[a], search_rovno(env2[i])) == 0)
			{
				env2 = unset_arg(env2, i);
				i--;
			}
			i++;
		}
		i = 0;
		a++;
	}
	free_string1(env);
	return (env2);
}
