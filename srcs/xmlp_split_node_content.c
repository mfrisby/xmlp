/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp_split_node_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:40:13 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/01 16:53:30 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/xmlp.h"
#include <stdlib.h>

char		**xmlp_split_node_content(t_xmlp *xmlp, char *path, char delimiter)
{
	char	*content;
	char	**split;
	
	content = xmlp_get_node_content(xmlp, path);
	split = ft_strsplit(content, delimiter);
	return (split);
}