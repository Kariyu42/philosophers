# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 18:33:29 by kquetat-          #+#    #+#              #
#    Updated: 2023/09/28 12:50:36 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- SRC / OBJ --- #
SRC_PATH	=	./src/

SRC			=	${addprefix ${SRC_PATH}, main.c \
											addl_tools.c \
											handle_err.c \
											init.c \
											manage.c \
											routine.c \
											time.c \
											watcher.c}

OBJ			=	${SRC:.c=.o}

# --- COMPILER --- #
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread

# --- DEBUG PURPOSES --- #
ifdef	DEBUG
	CC	+=	-g
endif

HEADER		=	./inc/

${SRC_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -I${HEADER} -c $< -o $@

# --- EXEC / RULES --- #
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