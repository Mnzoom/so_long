# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 16:05:47 by clementngoi       #+#    #+#              #
#    Updated: 2026/05/09 16:59:01 by clementngoi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
GREEN = \033[0;92m

NAME          = so_long
CC            = cc
CFLAGS        = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT_DIR     = libft
LIBFT         = $(LIBFT_DIR)/libft.a

PRINTF_DIR    = printf
PRINTF        = $(PRINTF_DIR)/libftprintf.a

MINILIBX_DIR  = minilibx/minilibx_mac
MINILIBX      = $(MINILIBX_DIR)/libmlx.a

MLX_FLAGS     = -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit

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

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME)$(GREEN) generated"

$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(GREEN)libft generated"

$(PRINTF):
	@make -C $(PRINTF_DIR) > /dev/null 2>&1
	@echo "$(GREEN)printf generated"

$(MINILIBX):
	@make -C $(MINILIBX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)minilibx generated"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) clean > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) clean > /dev/null 2>&1
	@rm -f $(OBJS)
	@echo "$(YELLOW)Objects cleaned"

fclean: clean
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) fclean > /dev/null 2>&1
	@rm -f $(NAME)
	@echo "$(NAME)$(YELLOW) removed"

re: fclean all

.PHONY: all clean fclean re
