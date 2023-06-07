##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CFLAGS = -Wall -Wshadow -Wextra -I./include

SRC_MV    =	corewar/main.c	\
			corewar/op.c \
			corewar/get_args.c 	\
			corewar/loop.c 	\
			corewar/display.c 	\

OBJ_MV    =    $(SRC_MV:.c=.o)

NAME_MV	=	corewar/corewar

SRC_ASM    =	asm/main.c	\
				asm/op.c	\
				asm/conv_to_base.c	\
				asm/my_str_to_word_arr.c	\
				asm/process_line.c	\
				asm/utilities_functions.c	\
				asm/process_header.c	\
				asm/process_body.c	\
				asm/process_args.c	\
				asm/check_type.c	\
				asm/fill_file.c	\
				asm/print_args.c	\
				asm/process_body_labels.c	\
				asm/process_line_labels.c	\
				asm/get_bin_from_hexa.c	\
				asm/utilities_function_v2.c	\
				asm/do_if_command.c	\
				asm/do_if_command_labels.c	\
				asm/process_args_labels.c	\
				asm/print_labels.c	\
				asm/check_header_validity.c	\

OBJ_ASM    =    $(SRC_ASM:.c=.o)

NAME_ASM	=	asm/asm

all: $(NAME_MV) $(NAME_ASM)

$(NAME_ASM):	$(OBJ_ASM)
		make -C lib/my
		gcc -o $(NAME_ASM) $(OBJ_ASM) -Llib -lmy
$(NAME_MV):	$(OBJ_MV)
		make -C lib/my
		gcc -o $(NAME_MV) $(OBJ_MV) -Llib -lmy

clean:
		rm $(OBJ_ASM) || true
		rm $(OBJ_MV) || true

fclean: clean
		rm -f $(NAME_ASM) || true
		rm -f $(NAME_MV) || true

re:		fclean all

tests_run: all
	./tests/src/tester.sh

git:
	echo -e "*.a\n*.o\n*#*#*\n#*\n.#*\n*~" > .gitignore
	echo -e "vgcore*\n*.log\na.out\n.vscode*" >> .gitignore
	echo $(NAME_ASM) >> .gitignore
	echo $(NAME_MV) >> .gitignore

style:
	/home/${USER}/coding-style-checker/coding-style.sh . .
	grep -v MAJOR:C-O1 coding-style-reports.log || true
	rm -f coding-style-reports.log
