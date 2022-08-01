/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_redirect2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:43:23 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/13 13:43:48 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

char	*find_file_name(char *str, int i)
{
	int		l;
	int		j;
	char	*str2;

	while (str[i] == ' ')
		i++;
	l = i;
	j = 0;
	while (str[l] && str[l] != ' ')
	{
		l++;
		j++;
	}
	str2 = malloc(sizeof(char) * j + 1);
	if (!str2)
		return (NULL);
	ft_bzero(str2, (j + 1));
	l = i;
	j = 0;
	while (str[l] && str[l] != ' ')
		str2[j++] = str[l++];
	return (str2);
}

int	gnl_light(char **str)
{
	char	s[4096];
	char	r;
	int		i;
	int		x;

	i = 0;
	x = 1;
	ft_bzero(s, 4096);
	while (x > 0)
	{
		x = read(0, &r, 1);
		if (x > 0 && r != '\n')
			s[i] = r;
		if (x > 0 && r == '\n')
		{
			*str = s;
			return (1);
		}
		i++;
	}
	*str = s;
	return (0);
}

int	read_for_redirect(int *fd, char *str, int j, int x)
{
	int		l;
	int		y;
	int		pipefd[2];
	char	*gnl;

	if (pipe(pipefd) == -1)
		printf ("pipe error\n");
	if (pipe(pipefd) == -1)
		return (1);
	while (x)
	{
		l = 0;
		ft_putstr_fd("> ", 1);
		y = gnl_light(&gnl);
		l = ft_strlen(gnl);
		if (j > l)
			l = j;
		if (!ft_strncmp(gnl, str, l) || ft_strncmp(gnl, "", l) == 0)
			break ;
		write(pipefd[1], gnl, ft_strlen(gnl));
		write(pipefd[1], "\n", 1);
	}
	close(pipefd[1]);
	*fd = pipefd[0];
	return (0);
}

char	*left_redirect2(char *str, int i, int c, int *fd)
{
	int		j;
	char	*str1;
	char	*str2;
	char	*str3;

	str3 = find_file_name(str, i);
	j = ft_strlen(str3);
	read_for_redirect(fd, str3, j, 1);
	free(str3);
	str1 = ft_substr(str, 0, i - 3);
	str2 = ft_strdup(str + c);
	ft_bzero(str, '\0');
	str3 = ft_strjoin(str1, str2);
	ft_strlcpy(str, str3, ft_strlen(str3) + 1);
	free(str1);
	free(str2);
	free(str3);
	return (str);
}
