NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I. -I./mlx

MLX_DIR	= ./mlx
MLX_LIB	=  $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRCS	= 	main.c \
			parsing.c \
			utils.c \
			gameplay.c \
			pathfinding.c \
			is_map.c \
			sprite.c \
			utils.c \

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "so_long compilé avec succès pour macOS M2 !"

# Compilation de la MiniLibX si libmlx.a n'existe pas
$(MLX_LIB):
	@echo "🔨 Compilation de la MiniLibX..."
	@make -C $(MLX_DIR)

# Compilation des fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(MLX_DIR) clean
	rm -f $(OBJS)
	@echo "🧹 Fichiers objets supprimés."

fclean: clean
	rm -f $(NAME)
	@echo "🗑️ Exécutable supprimé."

re: fclean all

.PHONY: all clean fclean re
			


		 