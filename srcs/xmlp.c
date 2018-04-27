/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:14:18 by mfrisby           #+#    #+#             */
/*   Updated: 2018/04/27 18:30:53 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/xmlp.h"

t_xmlp		*new_xmlp(char *path)
{
	t_xmlp	*xmlp;

	xmlp = malloc(sizeof(t_xmlp));
	xmlp->fd = open_file(path);
	xmlp->path = path;
	read_file(xmlp->fd, xmlp);
	return (xmlp);
}