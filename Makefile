# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cn-goie <cn-goie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 00:00:00 by student           #+#    #+#              #
#    Updated: 2025/01/01 00:00:00 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

# ─── Compiler ─────────────────────────────────────────────────────────────── #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
RM			=	rm -f

# ─── Directories ──────────────────────────────────────────────────────────── #

SRCS_DIR	=	srcs
OBJS_DIR	=	objs
INC_DIR		=	includes
LIBFT_DIR	=	libft
PRINTF_DIR	=	printf
MLX_DIR		=	minilibx

# ─── Sources ──────────────────────────────────────────────────────────────── #

SRCS		=	$(SRCS_DIR)/main.c			\
				$(SRCS_DIR)/events.c		\
				$(SRCS_DIR)/free_all.c		\
				$(SRCS_DIR)/get_map_info.c	\
				$(SRCS_DIR)/get_next_line.c	\
				$(SRCS_DIR)/graphics.c		\
				$(SRCS_DIR)/map_verificator.c	\
				$(SRCS_DIR)/movements.c		\
				$(SRCS_DIR)/pathfinding.c

OBJS		=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# ─── Libraries ────────────────────────────────────────────────────────────── #

LIBFT		=	$(LIBFT_DIR)/libft.a
PRINTF		=	$(PRINTF_DIR)/libftprintf.a
MLX			=	$(MLX_DIR)/libmlx_Linux.a

# ─── Includes ─────────────────────────────────────────────────────────────── #

INC			=	-I $(INC_DIR)			\
				-I $(LIBFT_DIR)			\
				-I $(PRINTF_DIR)/inc	\
				-I $(MLX_DIR)

# ─── Linker flags ─────────────────────────────────────────────────────────── #

LDFLAGS		=	-L $(LIBFT_DIR) -lft			\
				-L $(PRINTF_DIR) -lftprintf		\
				-L $(MLX_DIR) -lmlx_Linux		\
				-lX11 -lXext

# ─── Colors ───────────────────────────────────────────────────────────────── #

GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
CYAN		=	\033[0;36m
RESET		=	\033[0m

# ─── Rules ────────────────────────────────────────────────────────────────── #

all:			$(NAME)

$(NAME):		$(LIBFT) $(PRINTF) $(MLX) $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
				@echo "$(GREEN)✓ $(NAME) compiled successfully$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
				@mkdir -p $(OBJS_DIR)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@
				@echo "$(CYAN)  Compiling $<$(RESET)"

$(LIBFT):
				@echo "$(YELLOW)  Building libft...$(RESET)"
				@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
				@echo "$(YELLOW)  Building ft_printf...$(RESET)"
				@$(MAKE) -C $(PRINTF_DIR) --no-print-directory

$(MLX):
				@echo "$(YELLOW)  Building minilibx...$(RESET)"
				@$(MAKE) -C $(MLX_DIR) --no-print-directory

clean:
				@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
				@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
				@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
				@$(RM) -r $(OBJS_DIR)
				@echo "$(YELLOW)✓ Object files removed$(RESET)"

fclean:			clean
				@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
				@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory
				@$(RM) $(NAME)
				@echo "$(YELLOW)✓ $(NAME) removed$(RESET)"

re:				fclean all

.PHONY:			all clean fclean re