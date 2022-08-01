/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:27:19 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:26:42 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		c;
	char	*t;

	if (s == NULL)
		return (NULL);
	t = (char *)s;
	c = ft_strlen(t);
	t = (char *)ft_strdup(s);
	if (!t)
		return (0);
	c = 0;
	while (s[c])
	{
		t[c] = f(c, s[c]);
		c++;
	}
	return (t);
}
