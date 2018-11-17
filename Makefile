# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyeo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 14:15:58 by jyeo              #+#    #+#              #
#    Updated: 2018/01/25 00:00:51 by jyeo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAG = -Wall -Wextra -Werror

CC = gcc

SRC =       		srcs/create_map.c\
					srcs/draw_line.c\
					srcs/draw_map.c\
					srcs/ft_check.c\
					srcs/hook.c\
					srcs/key_utils.c\
					srcs/main.c\

INCLUDES = -I includes

OBJ = $(SRC:.c=.o)
LIBS = -L libft/ -lft
MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx
OPENGL = -framework OpenGL -framework Appkit

all: lib $(NAME)

lib:
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(MLX) $(OPENGL)

$(OBJ): %.o: %.c
	$(CC) $(FLAG) $(INCLUDES) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	make clean -C libft/

fclean:	clean
	@/bin/rm -f $(NAME)
	make fclean -C libft/

re:	fclean all
