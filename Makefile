NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
RLFLAGS = -lreadline
SRCS =	./external/ft_printf/ft_printf.c \
		./external/libft_utils/ft_strlen.c \
		./external/libft_utils/ft_split_args.c \
		./src/main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(RLFLAGS)
	rm -f $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re