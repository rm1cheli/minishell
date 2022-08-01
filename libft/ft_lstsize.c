/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:25:57 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:25:10 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
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
