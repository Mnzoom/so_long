NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -I./mlx -I./libft -I./ft_printf -DGL_SILENCE_DEPRECATION

MLX_DIR     = ./mlx
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lz

LIBFT_DIR   = ./libft
PRINTF_DIR  = ./ft_printf
LIBS        = $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a

SRCS        = main.c \
              parsing.c \
              movement.c \
              pathfinding.c \
              is_map.c \
              sprite.c \
              game.c \
              utils.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ so_long compilé avec succès !"


$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	@make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re