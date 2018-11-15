##
## Makefile for Makefile in /home/roby_t/perso/test/01_hello_SDL
## 
## Made by Tristan Roby
## Login   <roby_t@epitech.net>
## 
## Started on  Mon Jan 19 17:58:39 2015 Tristan Roby
## Last update Sat Jan 24 14:54:54 2015 Tristan Roby
##

SRC=	main.cpp \
	Pokedex.cpp \
	aff_list.cpp \
	Pokemon.cpp \
	PokedexText.cpp
 
OBJ=	$(SRC:.cpp=.o)

NAME=	Pokedex

LIB=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(LIB) -Wall -Wextra -Werror

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
