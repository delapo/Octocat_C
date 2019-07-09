##
## ETNA PROJECT, 06/10/2018 by delapo_a
## my_printf Makefile
## File description:
##      Makefile to my_printf
##

CC		= gcc
AR 		= ar
CFLAGS	= -Wall -Wextra -Werror -fPIC
NAME	= libmy.a
NAMEDYN	= libmy_printf_`uname -m`-`uname -s`.so
RM		= rm -f

SRC		= \
		lib/my_nbrlen.c \
		lib/my_putchar.c \
		lib/my_putnbr.c \
		lib/my_putnbr_base.c \
		lib/my_putnbr_unsigned.c \
		lib/my_putstr.c \
		lib/my_strlen.c \
		lib/my_strcat.c \
		lib/my_strcpy.c \
		my_printf.c 


OBJ		= $(SRC:.c=.o)

my_printf_static: $(OBJ)
	$(AR) rcsT $(NAME) $(OBJ)
my_printf_dynamic: $(OBJ)
	$(CC) -shared  -o $(NAMEDYN) $(OBJ)
all: $(NAME) my_printf_static my_printf_dynamic
	$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re:
	fclean all
.PHONY:
	all $(NAME) clean fclean re
