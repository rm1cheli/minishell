/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dou_right_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:43:04 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/18 20:48:19 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"
#include <ctype.h>

char	*duo_right_redirect(char *str, int i, int c, int *fd)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str3 = ft_substr(str, i + 3, c - i - 2);
	*fd = open(str3, O_APPEND | O_CREAT | O_WRONLY | O_RDONLY, 0666);
	free(str3);
	str1 = ft_substr(str, 0, i);
	str2 = ft_strdup(str + c);
	ft_bzero(str, '\0');
	str3 = ft_strjoin(str1, str2);
	ft_strlcpy(str, str3, ft_strlen(str3) + 1);
	free(str1);
	free(str2);
	free(str3);
	return (str);
}
