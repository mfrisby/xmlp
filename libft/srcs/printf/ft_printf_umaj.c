/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_umaj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:15:15 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/11 13:15:16 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void		ft_printf_umaj(t_env *e)
{
	char				*tmp;
	unsigned long int	deci;

	deci = va_arg(e->pa, unsigned long int);
	tmp = ft_utoa_base(deci, 10);
	ft_printf_add_to_buffer(e, tmp, 0);
	ft_strdel(&tmp);
}
