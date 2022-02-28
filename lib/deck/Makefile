# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 18:05:21 by yunselee          #+#    #+#              #
#    Updated: 2022/02/25 18:58:54 by yunselee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME = libftdeck.a

SOURCES =	deck_initialize.c \
			deck_operator.c \
			deck_util.c \

OBJ		= ${SOURCES:.c=.o}
BONUS_OBJ = ${BONUS:.c=.o}

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@

$(NAME)	: ${OBJ}
	ar rc $@ $^

all : ${NAME}

bonus: ${OBJ} ${BONUS_OBJ}
	ar rc ${NAME} $^

clean :
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -rf ${NAME}

re : fclean	all

.PHONY: all bonus clean fclean re
