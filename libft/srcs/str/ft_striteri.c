/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:24:24 by mfrisby           #+#    #+#             */
/*   Updated: 2014/11/21 18:35:08 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;
	int e;

	if (s != NULL && f != NULL)
	{
		i = 0;
		e = ft_strlen(s);
		while (i < e)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
