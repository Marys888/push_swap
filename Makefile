# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/09 21:15:59 by msievier          #+#    #+#              #
#    Updated: 2026/09/09 21:16:01 by msievier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c \
	   stack.c \
	   stack_utils.c \
	   parse.c \
	   parse_utils.c \
	   swap.c \
	   push.c \
	   rotate.c \
	   reverse.c \
	   sort.c \
	   sort_simple.c \
	   sort_medium.c \
	   sort_complex.c \
	   sort_adaptive.c \
	   disorder.c \
	   bench.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all