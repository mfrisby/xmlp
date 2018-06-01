/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:50:26 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/01 16:53:35 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XMLP_H
# define XMLP_H

# include "../libft/includes/libft.h"

# define CLOSE 1
# define OPEN 2

typedef struct			s_xmlp
{
	int					fd;
	int					len;
	char				*path;
	char				*content;
	char				*status;
	struct s_node		*node;
}						t_xmlp;

typedef	struct			s_node
{
	char				*content;
	char				*name;
	struct s_node		*parent;
	struct s_node		*child;
	struct s_node		*next;
}						t_node;

//functions for lib not user 

void					read_file(int fd, t_xmlp *xmlp);
int						open_file(char *path);
char					*get_const_balise(char *name, int is_open);
t_xmlp					*new_xmlp(char *path);
void					node_parser(t_xmlp *xmlp);
t_node					*init_node(t_node *parent);
char					*get_balise_name(char *s, int i);
char					*get_balise_content(char *s, int i);
int						is_balise_closed(char *name, char *s);

//functions to call by user

char					*xmlp_get_node_content(t_xmlp *xmlp, char *path);
char					**xmlp_split_node_content(t_xmlp *xmlp,
							char *path, char delimiter);

#endif
