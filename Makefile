NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker

CC = gcc 
CFLAGSS = -Wall -Werror -Wextra
LFT = ./lib/libft/libft.a
LFTDECK = ./lib/deck/libftdeck.a


SRCS_PUSH_SWAP =	$(addprefix ./src/, \
					argument_passing.c \
					main_push_swap.c \
					push_swap.c \
					run_operator.c \
					sort_small.c \
					error_exit.c \
					)

SRCS_CHECKER =	$(addprefix ./src/, \
					argument_passing.c \
					main_checker.c \
					run_operator.c \
					error_exit.c \
					)

OBJ_PUSH_SWAP		= ${SRCS_PUSH_SWAP:.c=.o}
OBJ_CHECKER		= ${SRCS_CHECKER:.c=.o}

all : libft libftdeck push_swap checker

checker : $(OBJ_CHECKER)
	$(CC) $(CFLAGSS) -lc $(LFT) $(LFTDECK) $(OBJ_CHECKER) -o $(NAME_CHECKER)

push_swap : $(OBJ_PUSH_SWAP)
	$(CC) $(CFLAGSS) -lc $(LFT) $(LFTDECK) $(OBJ_PUSH_SWAP) -o $(NAME_PUSH_SWAP) 

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@

libft : 
	make -C ./lib/libft/

libftdeck : 
	make -C ./lib/deck/

clean :
	make clean -C ./lib/libft/ 
	make clean -C ./lib/deck/
	rm -f $(OBJ_CHECKER)
	rm -f $(OBJ_PUSH_SWAP)

fclean : clean
	make fclean -C ./lib/libft/
	make fclean -C ./lib/deck/
	rm -f $(NAME_PUSH_SWAP)
	rm -f $(NAME_CHECKER)

re : fclean all

.PHONY : all clean fclean re libft libftdeck 