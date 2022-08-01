/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:46:28 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/18 15:49:28 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	ft_lstadd_back1(t_minilist **lst, t_minilist *new)
{
	t_minilist		*lst2;

	if (!new)
		return ;
	lst2 = *lst;
	if (*lst == NULL)
		*lst = new ;
	else
	{
		while (lst2->next != NULL)
			lst2 = lst2->next;
		lst2->next = new;
	}
}

t_minilist	*ft_lstnew1(char *str, int type, char **env)
{
	t_minilist	*c;
	int			f;

	f = 0;
	c = standart_cmd(str, type, env);
	if (c != NULL)
		c->next = NULL;
	return (c);
}

int	ft_lstsize1(t_minilist *lst)
{
	size_t	c;

	c = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}
