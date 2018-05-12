/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_balise_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:38:02 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/12 16:45:24 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/xmlp.h"

int is_balise_closed(char *name, char *s)
{
	int i;

	i = 0;
	while (name[i] && s[i] && s[i] != '>')
	{
		if (s[i] != name[i])
			return (-1);
		i++;
	}
	if (s[i] == '>')
		return (1);
	return (-1);
}