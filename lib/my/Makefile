##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compile libmy, copy the buid lib to lib/ ,
## copy my.h to include/, and clean after
##

SRC    =	my_compute_power_rec.c    \
			my_compute_square_root.c    \
			my_find_prime_sup.c    \
			my_getnbr.c    \
			my_isneg.c    \
			my_is_prime.c    \
			my_putchar.c    \
			my_put_nbr.c    \
			my_putstr.c    \
			my_revstr.c    \
			my_strcapitalize.c    \
			my_strcat.c    \
			my_strcmp.c    \
			my_strcpy.c    \
			my_strdup.c    \
			my_str_isalpha.c    \
			my_str_islower.c    \
			my_str_isnum.c    \
			my_str_isprintable.c    \
			my_str_isupper.c    \
			my_strlen.c    \
			my_strlowcase.c    \
			my_strncat.c    \
			my_strncmp.c    \
			my_strncpy.c    \
			my_strupcase.c    \
			my_swap.c	\
			my_putcharerr.c \
			my_putstrerr.c	\
			my_nblen.c	\

OBJ    =    $(SRC:.c=.o)

NAME   =    my

all:   $(NAME)

$(NAME):	$(OBJ)
		ar rc lib$(NAME).a $(OBJ)
		cp lib$(NAME).a ..
		cp my.h ../../include

clean:
	  rm $(OBJ)

fclean: clean

re:    all fclean
