CC = cc
PROGRAM = push_swap

SRCS = main.c \
       ops/stack_ops.c \
       ops/push_pop_ops.c \
       ops/swap_ops.c \
       ops/rotate_ops.c \
       ops/rev_rotate_ops.c \
       parse/parser.c \
       parse/parse_utils.c \
        sort/check_sorted.c \
        sort/simple_sort.c \
        sort/medium_sort.c \
        sort/complex_sort.c \
        sort/disorder.c \
       utils/utils.c \
       utils/index_utils.c \
       utils/math_utils.c \
       utils/bench_print.c \
       libft/ft_split.c \
       libft/ft_atoi.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I.

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re
