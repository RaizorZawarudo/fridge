##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

SRC	=	src/main.c \
		src/set_ingredients.c \
		my_str_to_word_array.c \
		src/loop.c \
		src/loop_utils.c \

NAME	=	fridge

INC	=	-I include/

LMY	=	-L lib/my/ -lmy

all:	$(NAME) clean

$(NAME):
	make -C ./lib/my/
	gcc $(SRC) -o $(NAME) $(LMY) $(INC) -g3 -Wall -Wextra -W

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all