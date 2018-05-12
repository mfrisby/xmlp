# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 19:08:56 by mfrisby           #+#    #+#              #
#    Updated: 2018/05/12 16:38:54 by mfrisby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = xmlp.a

SRCS = 	srcs/open_file.c srcs/read_file.c srcs/get_const_balise.c srcs/xmlp.c \
		srcs/node_parser.c srcs/get_balise_name.c srcs/get_balise_content.c \
		srcs/is_balise_closed.c

OBJS = $(SRCS:.c=.o)

INC = -I ./incs

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@ar rc $(NAME) $(OBJS) $(LIBFT)
	@ranlib $(NAME)

objs:
	mkdir -p objs

clean:
	@make clean -C libft
	@rm -f $(OBJS)

fclean:	clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
