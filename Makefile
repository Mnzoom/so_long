DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
GREEN = \033[0;92m

NAME          = so_long
CC            = cc
# Ajout de -Imlx pour être sûr que le compilateur trouve les headers pendant l'édition de liens
CFLAGS        = -Wall -Wextra -Werror -g3

LIBFT_DIR     = libft
LIBFT         = $(LIBFT_DIR)/libft.a

PRINTF_DIR    = printf
PRINTF        = $(PRINTF_DIR)/libftprintf.a

# Correction du chemin ici pour correspondre à ton tree
MINILIBX_DIR  = minilibx/minilibx_lin
# Correction : on utilise MINILIBX_DIR au lieu de MLX_PATH qui n'existait pas
MLX_FLAGS     = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

INC           = -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(MINILIBX_DIR)

SRCS_DIR      = srcs
SRCS          = $(SRCS_DIR)/map_verificator.c \
                $(SRCS_DIR)/get_next_line.c \
                $(SRCS_DIR)/get_map_info.c \
                $(SRCS_DIR)/pathfinding.c \
                $(SRCS_DIR)/movements.c \
                $(SRCS_DIR)/free_all.c \
                $(SRCS_DIR)/graphics.c \
                $(SRCS_DIR)/events.c \
                $(SRCS_DIR)/main.c

OBJS         = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX_DIR)/libmlx.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME)$(GREEN) generated"
$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)libft generated"

$(PRINTF):
	@make -C $(PRINTF_DIR)
	@echo "$(GREEN)printf generated"

# La règle pour compiler la MLX si le .a n'existe pas$(MINILIBX_DIR)/libmlx.a:
	@echo "$(YELLOW)Compiling MinilibX..."
	@make -C $(MINILIBX_DIR) > /dev/null 2>&1

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	@rm -f $(OBJS)
	@echo "$(YELLOW)Objects cleaned"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)
	@echo "$(NAME)$(YELLOW) removed"

re: fclean all

.PHONY: all clean fclean re