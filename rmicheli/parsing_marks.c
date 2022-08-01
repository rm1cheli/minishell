/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_marks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:04:46 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/19 19:15:37 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"
#include <ctype.h>

char	*dollar(char *str, int *i, t_data *data)
{
	int		j[2];
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	j[0] = *i;
	while (str[++(*i)])
		if (!ifkey(str[*i]))
			break ;
	str1 = ft_substr(str, j[0] + 1, *i - j[0] - 1);
	str2 = search_env(str, j[0], i, data);
	j[1] = (ft_strlen(str1) - ft_strlen(str2));
	if (j[1] > 0 && ft_strlen(str2) != 0)
		*i = *i - j[1] + 1;
	free (str1);
	str1 = ft_substr(str, 0, j[0]);
	str3 = ft_strdup(str + *i);
	str4 = ft_strjoin(str1, str2);
	free_1(str1, str2);
	str1 = ft_strjoin(str4, str3);
	free_1(str3, str4);
	free(str);
	return (str1);
}

char	*quotation_marks1(char *str, int *i, int m)
{
	int		j;

	j = *i;
	while (str[++(*i)] && m == 1)
		if (str[*i] == '\'')
			m = 0 ;
	str = gl_hf(str, j, i);
	return (str);
}

char	*slesh(char *str, int *i)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_substr(str, 0, *i);
	str2 = ft_strdup(str + *i + 1);
	str3 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	free(str);
	*i = *i + 1;
	return (str3);
}

char	*quotation_marks2(char *str, int *i, t_data *data, int m)
{
	int		j[2];
	char	*str4;

	j[0] = *i;
	j[1] = 0;
	while (str[++(*i)] && m == 1)
	{
		if (str[*i] == '\"')
			m = 0 ;
		if (str[*i] == '\\' && str[*i + 1] && (str[*i + 1] == '\\' \
		|| str[*i + 1] == '\"' || str[*i + 1] == '$'))
			str = slesh(str, i);
		if (str[*i] == '$')
		{
			str4 = ft_strdup(str);
			str = dollar(str, i, data);
			j[1] = (ft_strlen(str) - ft_strlen(str4));
			if (j[1] < 0)
				j[1] = j[1] * -1;
			*i = *i - j[1];
			free(str4);
		}
	}
	str = gl_hf(str, j[0], i);
	return (str);
}

char	*quotation_marks(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			str = quotation_marks1(str, &i, 1);
		else if (str[i] == '\\')
			str = slesh(str, &i);
		else if (str[i] == '\"')
			str = quotation_marks2(str, &i, data, 1);
		else if (str[i] == '$')
			str = dollar(str, &i, data);
		else
			i++;
	}
	return (str);
}
