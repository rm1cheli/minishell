/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:26:52 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/29 13:41:33 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_sss(char **u)
{
	int	y;

	y = 0;
	while (u[y])
		free(u[y++]);
	free(u);
}

int	mas(char const *g, int c)
{
	size_t	words_count;
	size_t	word_len;
	char	*s;

	s = (char *)g;
	words_count = 0;
	word_len = 0;
	while (*s != '\0')
	{
		if (word_len == 0 && *s != c && *s != '\0')
		{
			words_count++;
			word_len = 1;
		}
		else if (word_len == 1 && *s == c)
			word_len = 0;
		s++;
	}
	return (words_count);
}

void	ft_split2(char const *s, char c, char **split)
{
	size_t	m;
	size_t	df;

	m = 0;
	while (*s)
	{
		if (*s != c)
		{
			df = 0;
			while (*s && *s != c && ++df)
				s++;
			split[m] = ft_substr(s - df, 0, df);
			if (!split[m++])
				free_sss(split);
		}
		else
			s++;
	}
	split[m] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = malloc((mas(s, c) + 1) * sizeof(char *));
	if (!split)
		ft_error("Error: ");
	ft_split2(s, c, split);
	return (split);
}
