/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:51:02 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:26:51 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	c;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen((char *)s) < len)
		len = ft_strlen((char *)s);
	t = (char *)malloc(sizeof(*t) * (len + 1));
	if (!t)
		ft_error("Error: ");
	c = 0;
	i = 0;
	while (s[c])
	{
		if (c == start)
			while (s[c] && len-- > 0)
				t[i++] = s[c++];
		c++;
		if (i > 0)
			break ;
	}
	t[i] = '\0';
	return (t);
}
