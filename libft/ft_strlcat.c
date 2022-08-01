/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:28:16 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/14 17:26:30 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	cpt;
	unsigned int	i;
	int				y;
	int				j;

	i = 0;
	cpt = ft_strlen(dst);
	y = ft_strlen((char *)src);
	j = cpt;
	if (cpt < size - 1 && size > 0)
	{
		while ((cpt + i < size - 1) && src[i])
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	if (cpt >= size)
		cpt = size;
	return (cpt + y);
}
