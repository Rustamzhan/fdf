# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 12:14:43 by kreilly           #+#    #+#              #
#    Updated: 2019/04/24 19:09:52 by kreilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/key.c srcs/rotation.c srcs/main_fdf.c srcs/coob.c srcs/key1.c\
		srcs/window.c srcs/print.c

OBJ = srcs/key.o srcs/rotation.o srcs/main_fdf.o srcs/coob.o srcs/key1.o\
		srcs/window.o srcs/print.o

GCC = gcc -Wall -Wextra -Werror

LIB = -L ./minilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(GCC) $(OBJ) $(LIB) -L ./libft -lft -o $(NAME)

$(OBJ): %.o: %.c
	$(GCC) -c $< -o $@ -I ./libft/ -I ./minilibx/

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all
