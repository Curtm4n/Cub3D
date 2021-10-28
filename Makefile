# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 20:12:41 by curtman           #+#    #+#              #
#    Updated: 2021/10/28 19:29:24 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

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
		utils.c \
		utils2.c \
		utils3.c \
		utils4.c \
		graphics.c \
		move.c \
		raycasting.c \
		raycasting2.c \
		horz_utils.c \
		vert_utils.c

SRCS_BONUS =	cub3d_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				get_next_line_utils2_bonus.c \
				parsing_bonus.c \
				parsing2_bonus.c \
				parsing3_bonus.c \
				parsing4_bonus.c \
				parsing5_bonus.c \
				texture_bonus.c \
				window_bonus.c \
				events_bonus.c \
				game_bonus.c \
				display_bonus.c \
				frame_bonus.c \
				utils_bonus.c \
				utils2_bonus.c \
				utils3_bonus.c \
				utils4_bonus.c \
				graphics_bonus.c \
				move_bonus.c \
				raycasting_bonus.c \
				raycasting2_bonus.c \
				horz_utils_bonus.c \
				vert_utils_bonus.c

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

OBJS_BONUS = $(addprefix srcs_bonus/,$(SRCS_BONUS:.c=.o))

CC = clang

CFLAGS = -Wall -Wextra -Werror

FT = -L lib/libft -lft

MLX = -L lib/mlx -lmlx -lX11 -lXext

MATH = -lm

RM = rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C lib/libft/ bonus
	make -C lib/mlx/
	echo "\033[36;1mCreation :\033[0m \033[35;4m$(NAME_BONUS)\033[0m"
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(FT) $(MATH) $(MLX)

$(NAME): $(OBJS)
	make -C lib/libft/ bonus
	make -C lib/mlx/
	echo "\033[36;1mCreation :\033[0m \033[35;4m$(NAME)\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT) $(MATH) $(MLX)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	make -C lib/libft/ clean
	make -C lib/mlx/ clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	make -C lib/libft/ fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus
