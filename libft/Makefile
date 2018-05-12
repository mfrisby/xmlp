# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 19:08:56 by mfrisby           #+#    #+#              #
#    Updated: 2018/03/13 14:16:56 by mfrisby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

STR = srcs/str/
MEM = srcs/mem/
PUT = srcs/put/
IS = srcs/is/
LST = srcs/lst/
PRINTF = srcs/printf/
OTHER = srcs/other/

SRCS = 	$(OTHER)ft_atoi.c $(OTHER)ft_bzero.c $(OTHER)get_next_line.c $(OTHER)ft_getnbr.c $(OTHER)ft_itoa.c\
		$(OTHER)ft_tolower.c $(OTHER)ft_toupper.c $(OTHER)ft_splitblank.c $(OTHER)ft_atof.c\
		$(IS)ft_isalnum.c $(IS)ft_isalpha.c $(IS)ft_isascii.c $(IS)ft_isdigit.c $(IS)ft_isprint.c\
		$(MEM)ft_memalloc.c $(MEM)ft_memccpy.c $(MEM)ft_memchr.c \
		$(MEM)ft_memcmp.c $(MEM)ft_memcpy.c $(MEM)ft_memdel.c $(MEM)ft_memmove.c $(MEM)ft_memset.c \
		$(PUT)ft_putchar.c $(PUT)ft_putchar_fd.c $(PUT)ft_putendl.c $(PUT)ft_putendl_fd.c \
		$(PUT)ft_putnbr.c $(PUT)ft_putnbr_fd.c $(PUT)ft_putstr.c $(PUT)ft_putstr_fd.c $(PUT)ft_putint.c \
		$(STR)ft_strcat.c $(STR)ft_strjoin_free.c \
		$(STR)ft_strchr.c $(STR)ft_strclr.c $(STR)ft_strcmp.c $(STR)ft_strcpy.c $(STR)ft_strdel.c \
		$(STR)ft_strdup.c $(STR)ft_strequ.c $(STR)ft_striter.c $(STR)ft_striteri.c $(STR)ft_strjoin.c \
		$(STR)ft_strlcat.c $(STR)ft_strlen.c $(STR)ft_strmap.c $(STR)ft_strmapi.c $(STR)ft_strncat.c \
		$(STR)ft_strncmp.c $(STR)ft_strncpy.c $(STR)ft_strnequ.c $(STR)ft_strnew.c $(STR)ft_strnstr.c \
		$(STR)ft_strrchr.c $(STR)ft_strsplit.c $(STR)ft_strstr.c $(STR)ft_strsub.c $(STR)ft_strtrim.c \
		$(LST)ft_lstnew.c $(LST)ft_lstdelone.c \
		$(PRINTF)ft_dprintf.c $(PRINTF)ft_sprintf.c $(PRINTF)ft_vprintf.c $(PRINTF)ft_vdprintf.c \
		$(PRINTF)ft_printf.c $(PRINTF)ft_fprintf.c $(PRINTF)ft_printf_modulo.c $(PRINTF)ft_printf_buffer_flush.c \
		$(PRINTF)ft_printf_add_to_buffer.c $(PRINTF)ft_printf_length.c $(PRINTF)ft_printf_parser.c\
	  	$(PRINTF)ft_printf_s.c $(PRINTF)ft_printf_smaj.c $(PRINTF)ft_printf_p.c $(PRINTF)ft_printf_putflags.c\
		$(PRINTF)ft_printf_di.c $(PRINTF)ft_printf_dmaj.c $(PRINTF)ft_printf_cmaj.c $(PRINTF)ft_printf_precision.c  \
		$(PRINTF)ft_printf_omaj.c $(PRINTF)ft_printf_o.c $(PRINTF)ft_printf_u.c $(PRINTF)ft_printf_conversion.c\
		$(PRINTF)ft_printf_umaj.c $(PRINTF)ft_printf_x.c $(PRINTF)ft_printf_xmaj.c $(PRINTF)ft_printf_c.c \
		$(PRINTF)ft_printf_remove_min.c $(PRINTF)ft_printf_unicode.c $(PRINTF)ft_printf_b.c\
		$(PRINTF)ft_stoa_base.c $(PRINTF)ft_utoa_base.c $(PRINTF)ft_printf_getspace.c \

OBJS = $(SRCS:.c=.o)

INC = -I ./includes

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
