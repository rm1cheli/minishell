/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:36:49 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/19 18:55:57 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	search_probel(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

char	**remove_(char *str, char **env)
{
	int		i;
	char	**env2;

	i = 0;
	while (env[i])
		i++;
	env2 = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "_=", 2) == 0)
			env2[i] = ft_strjoin("_=", str);
		else
			env2[i] = ft_strdup(env[i]);
		i++;
	}
	free_string1(env);
	env2[i] = NULL;
	return (env2);
}

char	**change_(char **env, t_minilist *lst)
{
	int		a;
	char	*str;
	char	**str2;

	a = 0;
	str2 = copy_mas(lst->cmd);
	str = NULL;
	while (str2[a])
	{
		str = ft_strjoin1(str, str2[a]);
		if (str2[a + 1] != NULL)
			str = ft_strjoin1(str, " ");
		a++;
	}
	a = 0;
	env = remove_(str, env);
	free(str);
	free_string1(str2);
	return (env);
}

void	pars(char *str, t_data *data)
{
	int			*fd;
	int			i;
	t_minilist	*lst;

	i = 1;
	lst = data->lst;
	data->lst = list_create(&(data->lst), str, data->env);
	if (data->lst == NULL)
	{
		data->res = 1;
		ft_free_data(lst);
		return ;
	}
	fd = ft_dup();
	while (lst && i++)
		lst = lst->next;
	lst = data->lst;
	while (i-- > 0)
		pipe_help(data);
	ft_dup1(fd);
	while (waitpid(-1, &data->res, 0) != -1)
		data->res = data->res / 256;
	ft_free_data(lst);
}

void	pars_line(char **env)
{
	char		*str;
	t_data		*data;
	int			i;

	i = 0;
	str = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	data_init(data);
	data->env = copy_mas(env);
	while (1)
	{
		str = readline("05-group ");
		if (str == NULL)
			sign_d();
		if (str[i] == ' ')
			i = search_probel(str);
		if (ft_strncmp(str, "\0", 1) != 0 && i != 1)
		{
			add_history(str);
			str = quotation_marks(str, data);
			data->lst = NULL;
			pars(str, data);
		}
	}
	free_string1(data->env);
}
