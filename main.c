/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:50:37 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/18 14:50:45 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/xmlp.h"
#include <stdio.h>

static void	recursive_node(t_node *node)
{
	printf("name: %s\ncontent: %s\n", node->name, node->content);
	if (node->child)
		recursive_node(node->child);
	if (node->next)
		recursive_node(node->next);
}

static void	read_xmlp(t_xmlp *xmlp)
{
	t_node	*node;

	if (!xmlp || !xmlp->node)
	{
		ft_putendl("\033[31m node is NULL \033[0m");
		return ;
	}
	node = xmlp->node;
	recursive_node(node);
}

int			main(int ac, char **av)
{
	t_xmlp	*xmlp;

	if (ac > 1)
	{
		xmlp = new_xmlp(av[1]);
		if (!xmlp)
		{
			ft_putendl("\033[31m Something went wrong \033[0m");
			return (-1);
		}
		read_xmlp(xmlp);
	}
	return (0);
}
