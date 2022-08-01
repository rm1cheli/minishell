/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:23:22 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:25:00 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*lst2;

	if (!new)
		return ;
	lst2 = *lst;
	if (lst2 == NULL)
		*lst = new ;
	else
	{
		while (lst2->next != NULL)
			lst2 = lst2->next;
		lst2->next = new;
	}
}
