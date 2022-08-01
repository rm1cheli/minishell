/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:07:21 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/18 16:08:56 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	*ft_dup(void)
{
	int	*fd;

	fd = malloc(sizeof(int) * 2);
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	return (fd);
}

void	ft_dup1(int *fd)
{
	dup2(fd[0], STDOUT_FILENO);
	dup2(fd[1], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	free(fd);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_data(t_minilist *lst4)
{
	t_minilist	*lst;
	t_minilist	*lst1;
	int			i;

	i = 0;
	lst1 = lst4;
	while (lst1)
	{
		lst = lst1->next;
		if (lst1->cmd)
			ft_free(lst1->cmd);
		free(lst1);
		lst1 = lst;
	}
	lst4 = NULL;
}

void	pipe_help(t_data *data)
{
	if (data->lst->type == 1)
		pipe_mini(data);
	commands(data, data->lst);
}
