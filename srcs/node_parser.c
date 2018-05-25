/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:02:09 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/25 15:09:55 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/xmlp.h"
#include <stdlib.h>

static int		get_content(t_node **node, char *s, int i, int *len)
{
	if (!(*node))
	{
		ft_putendl("\033[31m Erreur content sans balise \033[0m");
		(*len) = 0;
		return (i);
	}
	(*node)->content = get_balise_content(s + i, i);
	if ((*node)->content)
		i += ft_strlen((*node)->content);
	return (i);
}

static int		balise_closed(t_node **node, char *s, int i, int *len)
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
		(*len) = 0;
	}
	return (i);
}

static int		balise_opened(t_node **node, char *s, int i, int len)
{
	if ((*node) && !(*node)->child)
	{
		(*node)->child = init_node((*node));
		(*node) = (*node)->child;
	}
	else if ((*node) && (*node)->child)
	{
		(*node) = (*node)->child;
		while ((*node)->next)
			(*node) = (*node)->next;
		(*node)->next = init_node((*node)->parent);
		(*node) = (*node)->next;
	}
	(*node)->name = get_balise_name(s + i, i);
	i += ft_strlen((*node)->name);
	return (i);
}

static int		get_node(t_node *node, char *s, int i, int len)
{
	if (!s || !s[i] || i >= len)
		return (-1);
	if (s[i] == '<' && s[i + 1] && s[i + 1] == '/')
		i = balise_closed(&node, s, i + 2, &len);
	else if (s[i] == '<')
		i = balise_opened(&node, s, i + 1, len);
	else
		i = get_content(&node, s, i + 1, &len);
	if (i < len)
		i = get_node(node, s, i, len);
	return (i);
}

void			node_parser(t_xmlp *xmlp)
{
	int			ret;
	int			len;

	len = ft_strlen(xmlp->content);
	xmlp->node = init_node(NULL);
	ret = get_node(xmlp->node, xmlp->content, 0, len);
	if (ret == -1)
		xmlp->status = ft_strdup("\033[31m ERROR \033[0m");
	else if (ret > len)
		xmlp->status = ft_strdup("\033[33m WARNING \033[0m");
	else
		xmlp->status = ft_strdup("\033[32m SUCCESS \033[0m");
}
