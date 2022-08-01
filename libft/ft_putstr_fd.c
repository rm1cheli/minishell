/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:26:41 by rmicheli          #+#    #+#             */
/*   Updated: 2021/11/02 20:26:28 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	if (fd < 0)
		return ;
	if (s == NULL)
		return ;
	c = 0;
	while (s[c])
	{
		write(fd, &s[c], 1);
		c++;
	}
}
