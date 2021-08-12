SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

UNAME_S = $(shell uname -s)

SRC_PATH = ./src

SRC_NAME =	main.c path.c struct.c\
			check.c error.c\

LIBFT = ./libft/libft.a

OBJS = ${SRCS:.c=.o}

NAME = pipex

FLAGS = -Wall -Wextra -Werror -no-pie

HEADER = -I "./include" -I"./libft"

DEBUG = -g -std=c11 -fsanitize=address

CC = gcc

RM = rm -f

CD = cd

.c.o:
			${CC} ${FLAGS} ${HEADER} -c $< -o $@ ${DEBUG}

${NAME}:	${OBJS}
			cd libft; make;
			${CC} -o ${NAME} ${OBJS} ${FLAGS} ${LIBFT} ${DEBUG}

all:		${NAME}

clean:
			${RM} ${OBJS}
			cd libft; make clean;

fclean:		clean
			${RM} ${NAME}
			cd libft; make fclean;

re:			fclean all
			cd libft; make re;

.PHONY =	all clean fclean re
