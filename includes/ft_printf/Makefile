NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MY_SRCS := 	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_helper.c \
 
all: $(NAME)

OBJ := $(MY_SRCS:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
