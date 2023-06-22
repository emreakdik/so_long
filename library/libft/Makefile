NAME = libft.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC) 2> /dev/null
	@ar rc $(NAME) *.o 2> /dev/null
clean:
	/bin/rm -f  *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

.PHONY: all bonus clean fclean re