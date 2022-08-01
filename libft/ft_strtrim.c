/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:49:36 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/22 13:31:31 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	d;
	size_t	i;
	char	*y;

	d = 0;
	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	y = (char *)s1;
	while (y[i] && ft_strchr(set, y[i]))
		i++;
	d = ft_strlen(y + i);
	while (d > 0 && ft_strchr(set, (y + i)[d]))
		d--;
	p = ft_substr(y + i, 0, d + 1);
	return (p);
}
