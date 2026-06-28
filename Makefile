NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = conversion.c \
	conversion_helpers.c \
	dict_parse.c \
	dict_parse_helpers.c \
	entries_utils_1.c \
	entries_utils_2.c \
	main.c \
	str_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
