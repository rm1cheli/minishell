/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:08:48 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/13 14:02:31 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"
#include <curses.h>
#include <term.h>

void	ft_echo_help(t_minilist *lst, int y)
{
	while (lst->cmd[y])
	{
		printf("%s", lst->cmd[y]);
		if (lst->cmd[y + 1] && lst->cmd[y][0] != '\0')
			printf(" ");
		y++;
	}
}

void	ft_echo(t_minilist *lst)
{
	int	y;
	int	s;
	int	opt;

	y = 1;
	opt = 0;
	s = 0;
	while (lst->cmd[s])
		s++;
	if (s > 1)
	{
		while (lst->cmd[y] && ft_strncmp(lst->cmd[y], "-n", 100) == 0)
		{
			opt = 1;
			y++;
		}
		ft_echo_help(lst, y);
	}
	if (opt != 1)
		printf("\n");
}
