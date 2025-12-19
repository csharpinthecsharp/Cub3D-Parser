AKEFLAGS += -s

NAME	= cub3d
CC		= clang
CFLAGS	= -g -Wall -Wextra -Werror

SRCS	= main.c \
		  parsing/p_main.c \
		  parsing/parse_name.c \
		  parsing/parse_cub.c \
		  init/i_main.c \
		  free/f_main.c \

OBJS	= $(SRCS:.c=.o)
LIBFT 	= libft/libft.a
all: before $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

before:
	@echo "\033[0;32mCompiling..\033[0m"

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	@echo "\033[0;31mCompiled files have been removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re