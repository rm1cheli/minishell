/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:13:57 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/13 16:27:10 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	g;

	g = 0;
	while (s[g] != (unsigned char)c)
	{
		if (!s[g])
			return (0);
		++g;
	}
	return ((char *)&s[g]);
}
