##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## This is the Makefile of the project.
##

SRCS 		= 	sources/main.c						\
				sources/csfml.c 					\
				sources/car_move.c 					\
				sources/rendering_functions.c		\
				sources/key_handling.c 				\
				sources/lidar.c 					\

LIB			=	lib/my_putstr.c						\
				lib/my_strdup.c 					\
				lib/my_strcat.c 					\
				lib/my_strlen.c						\
				lib/my_strcpy.c 					\
				lib/my_strcmp.c	 					\
				lib/my_getnbr.c 					\
				lib/my_nbrlen.c						\
				lib/my_putnbr.c						\
				lib/my_arraylen.c 					\
				lib/my_arrayfree.c 					\
				lib/mini_printf.c					\
				lib/my_isalphanum.c 				\
				lib/my_separator.c 					\
				lib/my_str_to_word_array.c			\

CSFML		= 	-l csfml-graphics 			\
				-l csfml-window 			\
				-l csfml-system 			\
				-l csfml-audio


.PHONY: all tests tests_run fclean re all init

SRCS 		+= 	$(LIB)

CFLAGS 		= 	-Wextra -Wall -lm

OBJ 		=	$(SRCS:.c=.o)

NAME		= 	betterCoppelia

TESTS_FILES	=	tests/libtests.c 	\

TESTS_NAME 	= 	criterion_tests

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CSFML) $(CFLAGS)

init:
	@touch .gitignore
	@echo $(NAME) >> .gitignore

all: $(NAME)

tests:
	@gcc -o $(TESTS_NAME) $(LIB) $(TESTS_FILES) -lcriterion

tests_run: tests
	@./criterion_tests

clean:
	@rm -f *~
	@rm -f $(OBJ)
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f *.log
	@rm -f vgcore.*

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)