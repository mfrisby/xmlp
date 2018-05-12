/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dmaj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:11:47 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/11 13:12:06 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	ft_printf_dmaj(t_env *e)
{
	char				*tmp;
	signed long int		deci;

	tmp = NULL;
	deci = va_arg(e->pa, signed long int);
	tmp = ft_stoa_base(deci, 10);
	e->type = 'D';
	ft_printf_putflags(e, tmp);
}
