# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 20:12:41 by curtman           #+#    #+#              #
#    Updated: 2021/09/30 22:42:44 by cdapurif         ###   ########.fr        #
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
		window.c \
		events.c \
		game.c \
		display.c \
		frame.c \
		utils.c

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

CC = clang

CFLAGS = -Wall -Wextra -Werror

FT = -L lib/libft -lft

MLX = -L lib/mlx -lmlx -lX11 -lXext

MATH = -lm

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/libft/ bonus
	make -C lib/mlx/
	echo "\033[36;1mCreation :\033[0m \033[35;4m$(NAME)\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT) $(MATH) $(MLX)

clean:
	$(RM) $(OBJS)
	make -C lib/libft/ clean
	make -C lib/mlx/ clean

fclean: clean
	$(RM) $(NAME)
	make -C lib/libft/ fclean

re: fclean all

.PHONY: all clean fclean re
