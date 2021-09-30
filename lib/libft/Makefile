# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 16:32:03 by cdapurif          #+#    #+#              #
#    Updated: 2021/05/05 22:52:59 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c \
			ft_isalpha.c \
			ft_iswhitespace.c \
			ft_bzero.c \
			ft_isascii.c \
			ft_isalnum.c \
			ft_isdigit.c \
			ft_calloc.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memcmp.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_strchr.c \
			ft_putnbr_fd.c \
			ft_memmove.c \
			ft_strlcat.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strmapi.c \
			ft_strnstr.c \
			ft_split.c \
			ft_strrchr.c \
			ft_substr.c \
			ft_strlcpy.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strtrim.c

B_SRCS	=	ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstmap_bonus.c \
			ft_lst_at_bonus.c \

OBJS	=	${SRCS:.c=.o}

B_OBJS	=	${B_SRCS:.c=.o}

CC		=	gcc

NAME	=	libft.a

B_NAME =	libft_bonus.a

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

${OBJS} :	${SRCS}
			@${CC} ${CFLAGS} -c ${SRCS}

${B_OBJS} : ${B_SRCS}
			@${CC} ${CFLAGS} -c ${B_SRCS}

$(NAME) :	${OBJS}
			@ar Usurc ${NAME} ${OBJS}

bonus:		${OBJS} ${B_OBJS}
			@ar Usurc $(NAME) ${OBJS} ${B_OBJS}

clean:
					@${RM} ${OBJS}
					@${RM} ${B_OBJS}

fclean:		clean
					@${RM} $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
