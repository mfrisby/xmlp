/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:02:09 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/18 14:27:39 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/xmlp.h"

static int	get_content(t_node **node, char *s, int i, int len)
{
	if (!(*node))
	{
		ft_putendl("\033[31m Erreur content sans balise \033[0m");
		exit (0);
	}
	i++;
	(*node)->content = get_balise_content(s + i, i);
	i += ft_strlen((*node)->content);
	return (i);
}

static int	balise_closed(t_node **node, char *s, int i, int len)
{
	if ((is_balise_closed((*node)->name, s + i)) == 1)
	{
		while (s[i] != '>')
			i++;
		i++;
		(*node) = (*node)->parent;
	}
	else
	{
		ft_putendl("\033[31m Erreur balise fermante \033[0m");
		exit (0);
	}
	return (i);
}

static int	balise_opened(t_node **node, char *s, int i, int len)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->parent = (*node);
	new->next = NULL;
	new->child = NULL;
	new->content = NULL;
	new->name = get_balise_name(s + i, i);
	if (!(*node))
	{
		new->parent = NULL;
		(*node) = new;
	}
	else if (!(*node)->child)
		(*node)->child = new;
	else
	{
		(*node) = (*node)->child;
		while ((*node)->next)
			(*node) = (*node)->next;
		(*node)->next = new;
	}
	(*node) = new;
	i += ft_strlen((*node)->name);
	return (i);
}

static int get_node(t_node *node, char *s, int i, int len)
{
	if (!s || !s[i] || i >= len)
		return (-1);
	if (s[i] == '<' && s[i+1] && s[i+1] == '/')
		i = balise_closed(&node, s, i + 2, len);
	else if (s[i] == '<')
		i = balise_opened(&node, s, i + 1, len);
	else
		i = get_content(&node, s, i, len);
	if (i < len)
		i += get_node(node, s, i, len);
	return (i);
}

void		node_parser(t_xmlp *xmlp)
{
	int i;
	int len;
	char *s;

	i = 0;
	s = xmlp->content;
	len = ft_strlen(s);
	xmlp->node = malloc(sizeof(t_node));
	xmlp->node->name = NULL;
	xmlp->node->content = NULL;
	xmlp->node->child = NULL;
	xmlp->node->next = NULL;
	xmlp->node->parent = NULL;
	if (!get_node(xmlp->node, s, i, len))
	{
		ft_putendl("\033[31m ERROR \033[0m");
		exit(0);
	}
	ft_putendl("SUCCESS");
}