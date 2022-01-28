##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make library
##

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c			\
		my_getnbr.c					\
		my_isneg.c					\
		my_printf.c					\
		my_is_prime.c				\
		my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c					\
		my_revstr.c					\
		my_showmem.c				\
		my_showstr.c				\
		my_sort_int_array.c			\
		my_strcapitalize.c			\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c		\
		my_str_isupper.c			\
		my_strlen.c					\
		my_strlen_int.c 			\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c					\
		my_str_to_word_array.c		\
		my_strupcase.c				\
		my_swap.c

SRC2	=	my.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)
	make copy
	make clean

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../..
clean:
	rm -f *~

copy:
	mkdir -p ../../include/
	cp $(SRC2) ../../include/

fclean:
	make clean
	rm -f $(OBJ)
	rm -f libmy.a

re:
	make fclean
	make all
