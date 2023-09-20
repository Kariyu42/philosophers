# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 18:33:29 by kquetat-          #+#    #+#              #
#    Updated: 2023/09/20 18:31:03 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ COLORS ------------------------------ #
ITALIC		=	\033[3m
BOLD		=	\033[1m
RESET		=	\033[0m
BEIGE		=	\033[38;5;230m
CREAM		=	\033[38;5;255m
IVORY		=	\033[38;5;253m
OFF_WHITE	=	\033[38;5;251m
EGGSHELL	=	\033[38;5;251m
CHAMPAGNE	=	\033[38;5;224m

# ------------------------------ SRC / OBJ ------------------------------ #
SRC_PATH	=	./src/

SRC			=	${addprefix ${SRC_PATH}, main.c \
											addl_tools.c \
											handle_err.c \
											init.c \
											print_status.c \
											routine.c \
											time.c}

OBJ			=	${SRC:.c=.o}

# ------------------------------ COMPILER ------------------------------ #
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread

ifdef	DEBUG
	CFLAGS	+=	-fsanitize=thread -g3
endif

HEADER		=	./inc/

${SRC_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -I${HEADER} -c $< -o $@
# ------------------------------ EXEC / RULES ------------------------------ #
NAME	=	philo

all:	${NAME}

${NAME}:	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

debug:
	${MAKE} DEBUG=1

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean
	${MAKE} all

.PHONY: all debug clean fclean re