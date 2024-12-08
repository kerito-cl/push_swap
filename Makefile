
NAME = push_swap
SOURCES = push_swap.c ft_split.c ft_atoi.c cases.c \
			utils.c moves.c create_arr.c
OFILES = $(SOURCES:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -I. -o $@

clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all, clean, fclean, re
