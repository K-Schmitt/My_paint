##
## EPITECH PROJECT, 2022
## my_pushswap
## File description:
## Makefile
##

CC = gcc

CFLAGS = -W -Wall -Wextra -g2

INCLUDES = -I./includes

LFLAGS = -L.

LIBS = -lmy -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

SRC_PATH = src/

SRCS_NAME = *.c

MAIN = my_paint

SRCS = $(wildcard $(patsubst %, $(SRC_PATH)%, $(SRCS_NAME)))

OBJS = $(SRCS:.c=.o)

all : libs $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o :
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	make -C lib/my/ clean
	$(RM) $(OBJS) *~

fclean : clean
	make -C lib/my/ fclean
	rm -f $(wildcard lib/my/.# lib/my/*~)
	rm -f $(wildcard .# *~)
	rm -f $(wildcard vgcore.*)
	rm -r includes
	rm -f libmy.a
	$(RM) $(MAIN)

re : fclean all

libs :
	make -C lib/my/
	mv lib/my/libmy.a .
	mkdir -p ./includes
	cp -f lib/my/my.h ./includes/
	cp -f lib/my/printf/pmy.h ./includes/
	cp -f lib/my/csfmLib/csfmlib.h includes/
