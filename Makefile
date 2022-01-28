##
## EPITECH PROJECT, 2021
## minishell 1
## File description:
## Makefile
##

SRC	    =	src/file_1.c		\
			src/bootstrap.c 	\

OBJ = $(SRC:.c=.o)

NAME = mysh

CFLAGS	+= -Wall -Wextra -W -I include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)
	rm -f libmy.a

re: fclean	all

unit_tests:
	make clean -C tests
	make -C tests

tests_run:
	make run_tests -C tests

.PHONY: clean fclean re
