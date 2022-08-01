/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_command_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:21:24 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/18 15:49:41 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

char	*ft_strchr1(const char *s, int c)
{
	size_t	g;
	size_t	i;

	i = 0;
	while (s[i] != ' ' && s[i] != '\0')
		i++;
	g = 0;
	while (s[g] && s[g] != (unsigned char)c)
		++g;
	if (g >= i)
		return (0);
	return ((char *)&s[g]);
}

void	ft_error(char *er)
{
	perror (er);
	exit (0);
}

int	error1(const int errnum)
{
	if (errnum == 0)
		ft_putstr_fd(strerror(errno), 1);
	if (errnum == 1)
		ft_putstr_fd("Too less arguments", 1);
	if (errnum == 2)
		ft_putstr_fd("Cannot find binary of the given command", 1);
	if (errnum == 3)
		ft_putstr_fd("ft_strjoin fail", 1);
	exit(0);
	return (1);
}

void	ft_free_str_arr(char ***arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (arr[0][i])
	{
		free(arr[0][i]);
		arr[0][i] = NULL;
		i++;
	}
	free(arr[0]);
	arr[0] = NULL;
}

void	path_search_ultra_extra(char **program, char *tmp)
{
	free(program[0]);
	program[0] = ft_strdup(tmp);
}
