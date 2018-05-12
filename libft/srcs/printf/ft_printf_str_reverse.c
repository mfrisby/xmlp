/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_reverse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:15:02 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/11 13:15:04 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

char		*ft_printf_str_reverse(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = ft_strlen(str);
	if (!(tmp = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	tmp[j] = '\0';
	while (--j >= 0)
	{
		tmp[i] = str[j];
		i++;
	}
	return (tmp);
}
