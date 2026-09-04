NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -Ilibft

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		=	srcs/main.c \
				srcs/strategy_selector.c \
				srcs/parsing/parsing.c \
				srcs/parsing/parsing_utils.c \
				srcs/parsing/fill_stack.c \
				srcs/parsing/error.c \
				srcs/stack/stack_init.c \
				srcs/stack/stack_utils.c \
				srcs/stack/stack_free.c \
				srcs/operations/ops_swap.c \
				srcs/operations/ops_push.c \
				srcs/operations/ops_rotate.c \
				srcs/operations/ops_reverse_rotate.c \
				srcs/operations/ops_exec.c \
				srcs/indexing/indexing.c \
				srcs/disorder/disorder.c \
				srcs/strategies/sort_simple.c \
				srcs/strategies/sort_medium.c \
				srcs/strategies/sort_stubs.c \
				srcs/bench/bench.c

OBJS		= $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re