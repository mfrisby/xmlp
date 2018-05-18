/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:02:09 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/18 12:53:48 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/xmlp.h"

static int	get_content(t_node **node, char *s, int i, int len)
{
	if (!(*node) || !(*node)->parent)
	{
		printf("Erreur content sans balise");
		exit (0);
	}
	i++;
	(*node)->content = get_balise_content(s + i, i);
	i += ft_strlen((*node)->content);
	if ((*node)->content && (ft_strlen((*node)->content)) > 0)
		printf("content: %s\n", (*node)->content);
	return (i);
}

static int	balise_closed(t_node **node, char *s, int i, int len)
{
	i+=2;
	if ((is_balise_closed((*node)->name, s + i)) == 1)
	{
		printf("end: %s\n", (*node)->name);
		while (s[i] != '>')
			i++;
		i++;
		(*node) = (*node)->parent;
	}
	else
	{
		printf("Erreur balise fermante");
		exit (0);
	}
	return (i);
}

static int	balise_opened(t_node **node, char *s, int i, int len)
{
	t_node *new;

	i++;
	new = malloc(sizeof(t_node));
	new->parent = (*node);
	new->next = NULL;
	new->child = NULL;
	new->name = get_balise_name(s + i, i);
	if (!(*node)->child)
		(*node)->child = new;
	else
	{
		(*node) = (*node)->child;
		while ((*node)->next)
			(*node) = (*node)->next;
		(*node)->next = new;
	}
	(*node) = new;
	printf("name: %s\n", (*node)->name);
	i += ft_strlen((*node)->name);
	return (i);
}

static int get_node(t_node *node, char *s, int i, int len)
{
	if (!s || !s[i] || i >= len)
		return (-1);
	if (s[i] == '<' && s[i+1] && s[i+1] == '/')
		i = balise_closed(&node, s, i, len);
	else if (s[i] == '<')
		i = balise_opened(&node, s, i, len);
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
	t_node *node;

	i = 0;
	s = xmlp->content;
	len = ft_strlen(s);
	node = malloc(sizeof(t_node));
	node->parent = NULL;
	node->child = NULL;
	node->next = NULL;
	node->name = NULL;
	node->content = NULL;
	if (!get_node(node, s, i, len))
	{
		printf("ERROR\n");
		exit(0);
	}
	printf("SUCCESS\n");
	exit(0);
}