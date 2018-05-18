/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_balise_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:06:57 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/18 12:57:50 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../incs/xmlp.h"

/**
 * recupere le nom de la balise
 * <nom>
 **/
char		*get_balise_name(char *s, int i)
{
	int len;
	char *name;

	len = 0;
	while (s[len] != '>')
	{
		len++;
	}
	name = malloc(len);
	len = 0;
	while (s[len] != '>')
	{
		name[len] = s[len];
		len++;
	}
	name[len] = '\0';
	return (name);
}