/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:40:46 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:26:48 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	g;

	g = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)&s[g]);
	while (s[--g] != (unsigned char)c)
	{
		if (g <= 0)
			return (0);
		if (!s[g])
			return (0);
	}
	return ((char *)&s[g]);
}
