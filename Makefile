# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 19:08:56 by mfrisby           #+#    #+#              #
#    Updated: 2018/06/08 16:21:06 by mfrisby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = xmlp.a

IPATH = includes/

IPATHLIB = ../libft/includes

SRC = 	open_file.c \
 		read_file.c \
		get_const_balise.c \
		xmlp.c \
		node_parser.c \
		get_balise_name.c \
		get_balise_content.c \
		is_balise_closed.c init_node.c \
		xmlp_get_node_content.c xmlp_split_node_content.c

OBJ = $(SRC:%.c=%.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ):%.o: %.c
	gcc $(FLAG) -o $@ -c $< -I$(IPATH) -I$(IPATHLIB)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
