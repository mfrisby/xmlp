/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:02:09 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/12 16:45:14 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/xmlp.h"
static int get_node(t_node *node, char *s, int i, int len)
{
	if (!s || !s[i])
		return (-1);
	if (s[i] == '<')
	{
		i++;
		if (s[i] == '/')
		{
			i++;
			if ((is_balise_closed(node->name, s + i)) == 1)
			{
				while (s[i] != '>')
					i++;
				i++;
				node = node->parent;
			}
			else
			{
				printf("Erreur balise fermante");
				exit (0);
			}
		}
		else
		{
			node->child = malloc(sizeof(t_node));
			node->child->parent = node;
			node = node->child;
			node->name = get_balise_name(s + i, i);
			printf("name: %s\n", node->name);
			i += ft_strlen(node->name);
		}
	}
	else
	{
		i++;
		node->content = get_balise_content(s + i, i);
		i += ft_strlen(node->content);
		if (node->content && (ft_strlen(node->content)) > 0)
			printf("content: %s\n", node->content);
	}
	if (i < len)
		i += get_node(node, s, i, len);
	return (i);
}

void		node_parser(t_xmlp *xmlp)
{
	int i;
	int len;
	char *s;
	t_node *node;

	i = 0;
	s = xmlp->content;
	len = ft_strlen(s);
	node = malloc(sizeof(t_node));
	int ret = get_node(node, s, i, len);
	if (ret == -1)
	{
		printf("ERROR\n");
		exit(0);
	}
	if (ret >= len)
	{
		printf("SUCCESS\n");
		exit(0);
	}
}