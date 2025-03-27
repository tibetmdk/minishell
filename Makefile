NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./external/ft_printf/ft_printf.c ./src/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	rm -f $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re