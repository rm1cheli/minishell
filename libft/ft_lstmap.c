/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:25:21 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:23:29 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*u;
	t_list	*h;

	h = NULL;
	if (!lst)
		return (0);
	while (lst)
	{
		u = ft_lstnew(f(lst->content));
		if (!u)
			del(u);
		ft_lstadd_back(&h, u);
		lst = lst->next;
	}
	return (h);
}
