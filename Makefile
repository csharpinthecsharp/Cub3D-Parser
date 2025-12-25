NAME	= cub3d
CC		= clang
CFLAGS	= -g -Wall -Wextra -Werror

SRCS	= main.c \
		  parsing/p_entry.c \
		  parsing/p_name.c \
		  parsing/p_cub.c \
		  parsing/p_utils.c \
		  parsing/p_format.c \
		  parsing/p_color_format.c \
		  parsing/p_path_format.c \
		  parsing/p_map_format.c \
		  parsing/p_global_format.c \
		  parsing/p_alloc_sizes.c \
		  parsing/p_init.c \
		  parsing/p_free.c \

OBJS	= $(SRCS:.c=.o)
LIBFT 	= libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re