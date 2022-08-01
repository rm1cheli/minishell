/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:22:38 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:24:58 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	revstr(char *str1)
{
	int	i;
	int	len;
	int	temp;

	len = ft_strlen(str1);
	i = 0;
	while (i < len / 2)
	{
		temp = str1[i];
		str1[i] = str1[len - i - 1];
		str1[len - i - 1] = temp;
		i++;
	}
}

char	*vid(int c)
{
	char	*t;
	int		f;

	f = 0;
	while (c != 0)
	{
		c /= 10;
		f++;
	}
	t = malloc(f + 2);
	if (!t)
		return (0);
	return (t);
}

char	*ft_itoa(int n)
{
	size_t	f;
	char	*t;
	long	y;

	f = 0;
	t = vid(n);
	if (!t)
		return (0);
	y = n;
	if (n < 0)
		y *= -1;
	while (y != 0)
	{
		t[f++] = (y % 10) + '0';
		y /= 10;
	}
	if (n < 0)
		t[f] = '-';
	if (f == 0)
		t[f] = '0';
	if (n <= 0)
		t[++f] = '\0';
	t[f] = '\0';
	revstr(t);
	return (t);
}
