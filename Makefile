
##
## EPITECH PROJECT, 2020
## bootsrap my_printf
## File description:
## Makefile
##

CC	= gcc

CFLAGS	= -W -Wall -Wextra

CPPFLAGS	= -I./include -L. -lmy -lncurses

SRC	= $(wildcard lib/my/*.c)

OBJ	= $(SRC:.c=.o)

LIB	= libmy.a

SRC2	= $(wildcard *.c)

NAME = my_sokoban

all:	$(LIB)
	$(CC) -o $(NAME) $(SRC2) $(CPPFLAGS)

$(LIB):	$(OBJ)
	$(AR) rsc $(LIB) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) #*#
	$(RM) $(LIB)

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all