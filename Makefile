NAME	= cub3d
CC		= clang
CFLAGS	= -g -Wall -Wextra -Werror

MLX_FILE	=	libmlx.a
MLX_PATH	=	./mlx/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_FLAGS	=	-L$(MLX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

SRCS	= main.c \
		  parsing/p_entry.c \
		  parsing/p_name_check.c \
		  parsing/p_open_cub.c \
		  parsing/p_utils.c \
		  parsing/p_format.c \
		  parsing/p_alloc_sizes.c \
		  init/i_main.c \
		  free/f_main.c \

OBJS	= $(SRCS:.c=.o)
LIBFT 	= libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(MLX_LIB):
	make -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_PATH) -O3 -c $< -o $@

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)
	@make clean -sC $(MLX_PATH)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re