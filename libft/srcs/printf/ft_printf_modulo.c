/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modulo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:12:32 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/11 13:12:33 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	ft_printf_modulo(t_env *e)
{
	char *s;

	s = ft_strnew(2);
	s[0] = '%';
	s[1] = '\0';
	e->precision = 0;
	ft_printf_putflags(e, s);
}
