NAME = push_swap

LIBFT = includes/libft/libft.a
OPERATORS = operators/
SORTING = sorting/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

COMMANDS = $(OPERATORS)error_handling.c \
				 $(OPERATORS)push.c \
				 $(OPERATORS)rotate.c \
				 $(OPERATORS)reverse_rotate.c \
				 $(OPERATORS)swap.c \
				 $(OPERATORS)split.c 


SORTING = $(SORTING)init_a.c \
			$(SORTING)init_b.c \
			$(SORTING)initialization.c \
			$(SORTING)sort_three.c \
			$(SORTING)utils.c \

SRCS = $(COMMANDS) $(SORTING)
OBJ = $(SRCS:.c=.o)

$(LIBFT):
	@make -C includes/libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
