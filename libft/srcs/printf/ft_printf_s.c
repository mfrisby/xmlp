/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:14:15 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/11 13:16:36 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	ft_printf_s(t_env *e)
{
	char *tmp;
	char *s;

	tmp = NULL;
	if (e->m_l == 1)
	{
		ft_printf_smaj(e);
		return ;
	}
	else
		s = va_arg(e->pa, char*);
	e->type = 's';
	if (s == NULL)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(s);
	if (tmp != NULL && e->precision >= 0 && e->precision < (int)ft_strlen(tmp)
			&& tmp[e->precision])
		tmp[e->precision] = '\0';
	ft_printf_putflags(e, tmp);
}
