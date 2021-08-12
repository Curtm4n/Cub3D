# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 20:12:41 by curtman           #+#    #+#              #
#    Updated: 2021/05/11 21:43:45 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	cub3d.c \
		get_next_line.c \
		get_next_line_utils.c \
		get_next_line_utils2.c \
		parsing.c \
		parsing2.c \
		parsing3.c \
		parsing4.c \
		parsing5.c \
		texture.c \
		window.c

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

FT = -L libft -lft

MLX = -L mlx -lmlx -lX11 -lXext

MATH = -lm

RM = rm -f

GREEN = \x1b[32m
RESET = \e[0m

all: $(NAME)

$(NAME): $(OBJS)
	@#echo "\n\033[36mCreation :\033[0m \033[35;4m$(NAME)\033[0m\n"
	make -C libft/ bonus
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT) $(MATH) $(MLX)

clean:
	$(RM) $(OBJS)
	make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re

#.SILENT: $(OBJS) $(NAME) clean fclean
