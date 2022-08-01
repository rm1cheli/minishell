/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_marks_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:04:41 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/19 19:14:24 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	free_1(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

int	ifkey(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

char	*gl_hf(char *str, int j, int *i)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_substr(str, 0, j);
	str2 = ft_substr(str, j + 1, *i - j - 2);
	str3 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	str1 = ft_strdup(str + *i);
	str2 = ft_strjoin(str3, str1);
	free(str3);
	free(str1);
	free(str);
	*i = *i - 2;
	return (str2);
}

char	*search_env(char *str, int j, int *i, t_data *data)
{
	char	*str1;
	char	*str2;
	int		c;

	c = -1;
	str1 = ft_substr (str, j + 1, *i - j - 1);
	str2 = ft_strjoin (str1, "=");
	if (ft_strlen(str2) == 1 && str[j + 1] == '?' && (*i)++)
	{
		free_1(str1, str2);
		return (ft_itoa(data->res));
	}
	while (data->env[++c])
	{
		if (ft_strncmp(str2, data->env[c], search_rovno(str2) + 1) == 0)
		{
			free_1(str1, str2);
			str2 = ft_strdup(data->env[c] + search_rovno(data->env[c]) + 1);
			return (str2);
		}
	}
	free_1(str1, str2);
	str2 = ft_strdup("");
	return (str2);
}
