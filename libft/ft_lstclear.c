/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:23:50 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:23:25 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void*))
{
	t_list	*l;
	t_list	*m;

	l = *lst;
	while (l)
	{
		m = l->next;
		if (l->content)
			del(l->content);
		free(l);
		l = m;
	}
	*lst = NULL;
}
