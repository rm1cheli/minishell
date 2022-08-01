/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:31:15 by rmicheli          #+#    #+#             */
/*   Updated: 2022/01/16 15:02:32 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	cpt;
	unsigned int	i;

	cpt = 0;
	i = 0;
	while (src[cpt] != '\0')
		cpt++;
	if (size == 0)
		return (cpt);
	else
	{
		while (i < cpt && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (cpt);
}
