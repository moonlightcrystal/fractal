# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 21:52:06 by kcorie            #+#    #+#              #
#    Updated: 2021/02/04 21:52:06 by kcorie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Werror -Wextra -I.
SRC = \
	src/fractal.c \
	src/hook.c \
	src/main.c \
	src/paint.c \
	src/render.c

OBJ =  \
	src/fractal.o \
	src/hook.o \
	src/main.o \
	src/paint.o \
	src/render.o

H = src/fractol.h

all: $(NAME)

%.o: %.c $(H)
	@gcc -c -o $@ $< $(FLAGS)
	@echo "*\c"

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(OBJ) $(FLAGS) -o $(NAME) \
		-lmlx -L./libft -lft -lpthread -framework OpenGL -framework AppKit
	@echo "$(NAME) created."

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJ)
	@echo "src/*.o deleted."

fclean: clean
	@/bin/rm -f libft/libft.a
	@/bin/rm -f $(NAME)
	@echo "$(NAME) deleted."

re: fclean all