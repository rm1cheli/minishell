/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:45:55 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:25:43 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *t, const void *y, size_t n)
{
	size_t		a;
	char		*f;
	const char	*x;

	a = 0;
	f = (char *)t;
	x = (char *)y;
	if (y == NULL && t == NULL)
		return (NULL);
	while (a < n)
	{
		f[a] = x[a];
		a++;
	}
	return (t);
}
