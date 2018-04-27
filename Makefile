# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 19:08:56 by mfrisby           #+#    #+#              #
#    Updated: 2018/04/27 18:17:30 by mfrisby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = xmlp.a

#STR = srcs/str/

SRCS = 	srcs/open_file.c srcs/read_file.c srcs/get_const_balise.c srcs/xmlp.c
#		$(PRINTF)ft_stoa_base.c $(PRINTF)ft_utoa_base.c $(PRINTF)ft_printf_getspace.c \

OBJS = $(SRCS:.c=.o)

INC = -I ./incs

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

objs:
	mkdir -p objs

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
