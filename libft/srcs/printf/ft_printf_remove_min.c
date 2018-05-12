/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_remove_min.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:13:56 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/11 13:13:58 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

char	*remove_min(t_env *e, char *tmp)
{
	int i;
	int y;

	i = 1;
	y = 0;
	if (tmp[0] != '-')
		return (tmp);
	while (tmp[i])
	{
		tmp[y] = tmp[i];
		i++;
		y++;
		tmp[y] = '\0';
	}
	e->neg = 1;
	return (tmp);
}
