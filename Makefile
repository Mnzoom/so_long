# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/20 11:21:21 by cn-goie           #+#    #+#              #
#    Updated: 2026/05/20 11:25:14 by cn-goie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

MAKEFLAGS += -s

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
				@printf "$(GREEN)✓ $(NAME) compiled successfully$(RESET)\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
				@mkdir -p $(OBJS_DIR)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@
				@printf "$(CYAN)  Compiling $<$(RESET)\n"

$(LIBFT):
				@printf "$(YELLOW)  Building libft...$(RESET)\n"
				@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
				@printf "$(YELLOW)  Building ft_printf...$(RESET)\n"
				@$(MAKE) -C $(PRINTF_DIR) --no-print-directory

$(MLX):
				@printf "$(YELLOW)  Building minilibx...$(RESET)\n"
				@$(MAKE) -C $(MLX_DIR) --no-print-directory > /dev/null 2>&1

clean:
				@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
				@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
				@$(MAKE) -C $(MLX_DIR) clean --no-print-directory > /dev/null 2>&1
				@$(RM) -r $(OBJS_DIR)
				@printf "$(YELLOW)✓ Object files removed$(RESET)\n"

fclean:			clean
				@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
				@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory
				@$(RM) $(NAME)
				@printf "$(YELLOW)✓ $(NAME) removed$(RESET)\n"

re:				fclean all

.PHONY:			all clean fclean re