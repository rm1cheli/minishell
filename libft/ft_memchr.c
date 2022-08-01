/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:41:45 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:25:22 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t				v;
	const unsigned char	*y;

	y = (unsigned char *)arr;
	v = 0;
	while (v < n)
	{
		if ((unsigned char)c == y[v])
			return ((void *)&arr[v]);
		v++;
	}
	return (NULL);
}
