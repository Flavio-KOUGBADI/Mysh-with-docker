##
## EPITECH PROJECT, 2025
## ld
## File description:
## dl
##

CC = clang

SRC =   src/the_shell_loop.c    \
	src/my_strdup.c     \
	src/my_strlen.c     \
	src/my_strcmp.c     \
	src/clean_str.c     \
	src/my_strcpy.c     \
	src/builtins.c  \
	src/utils.c     \
	src/utils1.c \
	src/print_exit.c    \
	src/execute.c   \
	src/linked_list.c   \
	src/my_getnbr.c     \
	src/my_strcat.c     \
	src/my_strncmp.c    \
	src/main.c  \

NAME = mysh

all: $(NAME)

$(NAME):
	unzip library.zip
	$(CC) -o $(NAME) $(SRC) libmy.a -g3
	rm -f *.a
	rm -rf *.o
	rm -rf *~
clean:
	rm -f *#
	rm -f *.o
	rm -f *.a

fclean: clean
	rm -f $(NAME)
	rm -f *.~
	rm -f *.a
	rm -rf src/*.o

re: fclean all

debug_v: re
	./valgrind $(NAME)
