# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 18:33:29 by kquetat-          #+#    #+#              #
#    Updated: 2023/09/22 19:16:19 by kquetat-         ###   ########.fr        #
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
	CFLAGS	+=	-fsanitize=address -g3
endif

# --- DATA RACE DEBUG --- #
ifdef	THREAD
	CFLAGS	+=	-fsanitize=thread -g3
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

thread:
	${MAKE} THREAD=1

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean
	${MAKE} all

.PHONY: all debug thread clean fclean re