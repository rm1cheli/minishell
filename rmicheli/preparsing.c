/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:04:49 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/17 16:42:02 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	preparser_marks(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if (str[c] == '\'')
		{
			c++;
			while (str[c] && str[c] != '\'')
				c++;
			if (!str[c] || str[c] != '\'')
			{
				printf("Imput error: \'\n");
				return (1);
			}
		}
		c++;
	}
	return (0);
}

int	preparser_marks2(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if (str[c] == '\"')
		{
			c++;
			while (str[c] && (str[c] != '\"' || \
			(str[c - 1] && str[c - 1] == '\\')))
				c++;
			if (!str[c] || str[c] != '\"')
			{
				printf("Imput error: \"\n");
				return (1);
			}
		}
		c++;
	}
	return (0);
}

int	preparser_p(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if (str[c] == '|' && str[c + 1] && str[c + 1] == '|')
		{
			printf("syntax error near unexpected token `|'\n");
			return (1);
		}
		if (str[c] == ';' && str[c + 1] && str[c + 1] == ';')
		{
			printf("syntax error near unexpected token `;'\n");
			return (1);
		}
		c++;
	}
	return (0);
}

int	preparser_redirect(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if ((str[c] == '<' && str[c + 1] && str[c + 1] == '>') || \
		(str[c] == '>' && str[c + 1] && str[c + 1] == '<'))
		{
			printf("Imput error: <>\n");
			return (1);
		}
		if ((str[c] == '<' && str[c + 1] && str[c + 1] == '<' && str[c + 2] && \
		str[c + 2] == '<') || (str[c] == '>' && str[c + 1] && str[c + 1] == '>' \
		&& str[c + 2] && str[c + 2] == '>'))
		{
			printf("Imput error: <>\n");
			return (1);
		}
		c++;
	}
	return (0);
}

int	preparser(char *str)
{
	if (preparser_marks(str))
		return (1);
	if (preparser_marks2(str))
		return (1);
	if (preparser_p(str))
		return (1);
	if (preparser_redirect(str))
		return (1);
	return (0);
}
