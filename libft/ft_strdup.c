/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:27:08 by rmicheli          #+#    #+#             */
/*   Updated: 2022/01/17 13:54:19 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*y;
	int		u;

	u = ft_strlen((char *)str);
	y = malloc(sizeof(*y) * (u + 1));
	if (!y)
		return (0);
	u = 0;
	while (str[u])
	{
		y[u] = str[u];
		u++;
	}
	y[u] = '\0';
	return (y);
}
