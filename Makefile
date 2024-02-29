
NAME = push_swap

SRC = src/main.c src/ft_afunction.c src/ft_bfunction.c src/ft_error.c src/ft_five.c src/ft_lst.c src/ft_free.c src/ft_getindex.c src/ft_pushclose.c src/ft_sortft.c src/ft_sorth.c src/ft_three.c src/ft_utils.c src/ft_sortfh.c src/ft_split.c src/ft_error2.c

CC = cc

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

all:	${NAME}

${NAME}: ${OBJ}
		${CC} ${FLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
