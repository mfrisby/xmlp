/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:50:26 by mfrisby           #+#    #+#             */
/*   Updated: 2018/04/27 18:30:19 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XMLP_H
# define XMLP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_xmlp
{
	int					fd;
	int					len;
	char				*path;
	char				*content;
}						t_xmlp;

typedef	struct			s_node
{
	struct s_node		*parent;
	struct s_node		*child;
	char				*content;
	char				*name;
}						t_node;

void					read_file(int fd, t_xmlp *xmlp);
int						open_file(char *path);
char					*get_const_balise(char *name, int is_open);
t_xmlp					*new_xmlp(char *path);

#endif
