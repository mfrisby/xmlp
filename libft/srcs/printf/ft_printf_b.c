/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:08:02 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/12 14:09:26 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void		ft_printf_b(t_env *e)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_stoa_base(va_arg(e->pa, int), 2);
	e->type = 'b';
	if (ft_strcmp(tmp, "0") == 0 && e->precision == 0)
		ft_printf_putflags(e, ft_strdup(""));
	else
		ft_printf_putflags(e, tmp);
}
