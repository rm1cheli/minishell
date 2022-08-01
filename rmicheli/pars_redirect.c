/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:04:37 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/18 15:49:54 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

char	*left_redirect(char *str, int i, int c, int *fd)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str3 = find_file_name(str, i);
	*fd = open(str3, O_RDONLY);
	free(str3);
	str1 = ft_substr(str, 0, i - 1);
	str2 = ft_strdup(str + c);
	ft_bzero(str, '\0');
	str3 = ft_strjoin(str1, str2);
	ft_strlcpy(str, str3, ft_strlen(str3) + 1);
	free(str1);
	free(str2);
	free(str3);
	return (str);
}

char	*right_redirect(char *str, int i, int c, t_minilist *lst)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str3 = find_file_name(str, i);
	lst->fd[1] = open(str3, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(str3);
	str1 = ft_substr(str, 0, i - 1);
	str2 = ft_strdup(str + c);
	ft_bzero(str, '\0');
	str3 = ft_strjoin(str1, str2);
	ft_strlcpy(str, str3, ft_strlen(str3) + 1);
	free(str1);
	free(str2);
	free(str3);
	return (str);
}

char	*redir_pars_help2(char *str, t_minilist *minilist, int i, int c)
{
	if (str[i] == '>')
	{
		minilist->fd[1] = -1;
		str = right_redirect(str, i + 1, c, minilist);
		i = 0;
	}
	else if (str[i] == '<')
	{
		minilist->fd[0] = -1;
		str = left_redirect(str, i + 1, c, &minilist->fd[0]);
		i = 0;
	}
	return (str);
}

char	*redir_pars_help(char *str, t_minilist *minilist, int i, int c)
{
	while (str[i] && i < c)
	{
		if (str[i] == '>' && str[i + 1] == '>')
		{
			minilist->fd[1] = -1;
			str = duo_right_redirect(str, i, c, &minilist->fd[1]);
			i = 0;
		}
		else if (str[i] == '<' && str[i + 1] == '<')
		{
			minilist->fd[0] = -1;
			left_redirect2(str, i + 3, c, &minilist->fd[0]);
			i = 0;
		}
		else
			str = redir_pars_help2(str, minilist, i, c);
		i++;
	}
	return (str);
}

char	*redirect_pars(char *str, int c, t_minilist *minilist)
{
	int		i;

	i = 0;
	minilist->fd[0] = -1;
	minilist->fd[1] = -1;
	redir_pars_help(str, minilist, i, c);
	return (str);
}
