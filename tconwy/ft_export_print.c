/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:42:40 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/18 20:47:21 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	export_printf(char **env)
{
	int	i[2];

	i[0] = 0;
	while (env[i[0]])
	{
		i[1] = 0;
		if (env[i[0]][0] == '_' && env[i[0]][1] == '=')
		{
			ft_putstr_fd("", 1);
			i[0]++;
		}
		ft_putstr_fd("declare -x ", 1);
		while (env[i[0]][i[1]] && env[i[0]][i[1]] != '=')
			ft_putchar_fd(env[i[0]][i[1]++], 1);
		if (!env[i[0]][i[1]])
			ft_putchar_fd('\n', 1);
		ft_putchar_fd('=', 1);
		ft_putchar_fd('"', 1);
		while (env[i[0]][i[1]] && env[i[0]][i[1]] != '\n')
			ft_putchar_fd(env[i[0]][++i[1]], 1);
		ft_putchar_fd('"', 1);
		ft_putchar_fd('\n', 1);
		i[0]++;
	}
	ft_free(env);
}
