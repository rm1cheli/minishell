/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:49:15 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:25:51 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *u, const void *b, size_t n)
{
	size_t				a;
	unsigned char		*f;
	const unsigned char	*x;

	f = (unsigned char *)u;
	x = (unsigned char *)b;
	a = 0;
	if (u == NULL && b == NULL)
		return (NULL);
	if (x < f)
	{
		while (++a <= n)
			f[n - a] = x[n - a];
	}
	else if (x > f)
	{
		a = 0;
		while (a < n)
		{
			f[a] = x[a];
			a++;
		}
	}
	return (u);
}
