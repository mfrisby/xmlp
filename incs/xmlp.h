/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:50:26 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/18 14:49:50 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XMLP_H
# define XMLP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct			s_xmlp
{
	int					fd;
	int					len;
	char				*path;
	char				*content;
	struct s_node		*node;
}						t_xmlp;

typedef	struct			s_node
{
	struct s_node		*parent;
	struct s_node		*child;
	struct s_node		*next;
	char				*content;
	char				*name;
}						t_node;

void					read_file(int fd, t_xmlp *xmlp);
int						open_file(char *path);
char					*get_const_balise(char *name, int is_open);
t_xmlp					*new_xmlp(char *path);
void					node_parser(t_xmlp *xmlp);
char					*get_balise_name(char *s, int i);
char					*get_balise_content(char *s, int i);
int						is_balise_closed(char *name, char *s);

#endif
