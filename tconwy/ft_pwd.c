/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:44:19 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/13 12:44:24 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"
#include <curses.h>
#include <term.h>

int	ft_pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, 1024))
	{
		ft_putendl_fd(cwd, 1);
		return (0);
	}
	else
		return (1);
}
