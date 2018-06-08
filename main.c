/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:50:37 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/01 16:57:34 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/xmlp.h"
#include <stdio.h>
#include <unistd.h>

static void	recursive_node(t_node *node)
{
	ft_putstr("name: ");
	ft_putstr(node->name);
	ft_putstr(" --- ");
	ft_putstr(" content: ");
	ft_putstr(node->content);
	ft_putchar('\n');
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
	if (xmlp->status)
		ft_putendl(xmlp->status);
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
		//read_xmlp(xmlp);
		char *content = xmlp_get_node_content(xmlp, "scene/cylindre/position");
		char **split = xmlp_split_node_content(xmlp, "scene/cylindre/position", ',');
		if (content)
			ft_putendl(content);
		else
			ft_putendl("null");
		int i = 0;
		while (split && split[i])
		{
			ft_putendl(split[i]);
			i++;
		}
	}
	return (0);
}
