/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:26:09 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:26:03 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	c;

	if (s == NULL || fd < 0)
		return ;
	c = 0;
	while (s[c])
	{
		write(fd, &s[c], 1);
		c++;
	}
	write(fd, "\n", 1);
}
