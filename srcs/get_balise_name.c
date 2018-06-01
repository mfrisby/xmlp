/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_balise_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:06:57 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/01 14:59:03 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../incs/xmlp.h"

char		*get_balise_name(char *s, int i)
{
	int		len;
	char	*name;

	len = 0;
	while (s[len] != '>')
		len++;
	name = ft_strnew(len + 1);
	len = 0;
	while (s[len] != '>')
	{
		name[len] = s[len];
		len++;
	}
	name[len] = '\0';
	return (name);
}
