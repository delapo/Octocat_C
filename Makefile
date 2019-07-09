##
## ETNA PROJECT, 10/05/2019 by courco_a
## octocat
## File description:
##      Makefil
##

CC          = gcc
CFLAGS      = -L ./printf -lmy -Werror -Wall -Wextra -g
NAME	    = octocat
make_lib 	= -C ./printf/
RM          = rm -f
OBJ	    =$(SRC:.c=.o)

SRC         = \
            main.c \
			menu.c \
			create_map.c \
			move_where.c \
			print_map.c \
			list.c \
			hardcore.c \
			my_read.c \
			free.c \

all: make_lib $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@cat ./src/octocat

make_lib: 
	make -C ./printf/

clean:
	$(RM) *.o

fclean: clean
	$(RM) octocat

clean_lib: 
		make -C ./printf/ clean

clean_all: clean clean_lib

fclean_all: clean clean_lib
	$(RM) octocat

re: clean_lib fclean all

.PHONY: all $(NAME) clean clean_all fclean re
