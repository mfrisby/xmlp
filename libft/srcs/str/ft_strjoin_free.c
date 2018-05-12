/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:18:40 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/11 13:18:40 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

char	*ft_strjoin_free(char *s1, char *s2, int rm)
{
	char	*str;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	str += ft_strlen(s1);
	str = ft_strcpy(str, s2);
	str -= ft_strlen(s1);
	if (rm == 1)
		ft_strdel(&s1);
	else if (rm == 2)
		ft_strdel(&s2);
	else if (rm == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
