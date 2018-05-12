/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_to_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:10:33 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/11 13:10:35 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	ft_printf_add_to_buffer(t_env *e, char *s, int start)
{
	while (e->index <= 3999 && s[start])
	{
		e->result[e->index] = s[start];
		e->index++;
		e->size++;
		start++;
	}
	if (e->index >= 3999)
	{
		e->result[e->index] = '\0';
		ft_printf_buffer_flush(e);
		ft_printf_add_to_buffer(e, s, start);
	}
}
