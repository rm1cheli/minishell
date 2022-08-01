/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:36:17 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/19 19:22:31 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	lst_init(t_minilist *lst)
{
	lst->cmd = NULL;
	lst->file_name = NULL;
	lst->value = NULL;
	lst->next = NULL;
	lst->prev = NULL;
}

char	*scrol(char *str, int *i)
{
	int		f;
	char	*str1;

	f = 0;
	str1 = NULL;
	while (str && str[f] != '|' && str[f] != ';' && str[f] != '\0')
		f++;
	str1 = ft_substr(str, f + 2, ft_strlen(str) - f + 1);
	free(str);
	*i = 0;
	return (str1);
}

int	search_cmd(char *str)
{
	int	c;

	c = 0;
	if (str[c] == '|' || str[c] == ';')
		c++;
	while (str[c] != '|' && str[c] != ';' && str[c] != '\0')
		c++;
	return (c);
}

t_minilist	*standart_cmd(char *str, int type, char **env)
{
	t_minilist	*minilist;
	int			c;
	char		*str1;

	c = 0;
	minilist = (t_minilist *)malloc(sizeof(t_minilist) + 1);
	lst_init(minilist);
	c = search_cmd(str);
	str = redirect_pars(str, c, minilist);
	c = 0;
	while (str[c] != '|' && str[c] != ';' && str[c] != '\0')
		c++;
	str1 = ft_substr(str, 0, c);
	minilist->cmd = pars_command(str1, env);
	minilist->type = type;
	if (str1)
		free(str1);
	if (minilist->cmd == NULL)
	{
		free(minilist);
		return (NULL);
	}
	return (minilist);
}

t_minilist	*list_create(t_minilist **minilist, char *str, char **env)
{
	int		i;

	i = 0;
	while (1)
	{
		if (str[i] == '|')
		{
			ft_lstadd_back1(minilist, ft_lstnew1(str, 1, env));
			str = scrol(str, &i);
		}
		if (str[i] == '\0')
		{
			ft_lstadd_back1(minilist, ft_lstnew1(str, 0, env));
			free(str);
			return (*minilist);
		}
		i++;
	}
	free(str);
	return (*minilist);
}
