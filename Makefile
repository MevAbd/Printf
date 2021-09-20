# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 02:56:46 by malbrand          #+#    #+#              #
#    Updated: 2021/09/16 03:49:57 by malbrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

GCC			= gcc -Wall -Werror -Wextra

SRC			+= printf.c
SRC			+= ft_sort.c
SRC			+= lib.c
SRC			+= lib2.c
SRC			+= sort_p.c
SRC			+= str_verif.c
SRC			+= itoa_base.c

OBJ	= printf.o\
			ft_sort.o \
	  		lib.o \
			lib2.o \
			sort_p.o \
			str_verif.o \
			itoa_base.o \
	  

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(GCC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re bonus
