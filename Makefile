# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/02 16:02:38 by cn-goie           #+#    #+#              #
#    Updated: 2026/05/02 16:05:59 by cn-goie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME          = so_long
CC            = cc
CFLAGS        = -Wall -Wextra -Werror

LIBFT_DIR     = libft
LIBFT         = $(LIBFT_DIR)/libft.a

PRINTF_DIR    = printf
PRINTF        = $(PRINTF_DIR)/libftprintf.a

MINILIBX_DIR  = minilibx-linux
MINILIBX      = $(MINILIBX_DIR)/libmlx_Linux.a

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
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MINILIBX) -L.. -Lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "$(NAME) generated"

$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "libft generated"

$(PRINTF):
	@make -C $(PRINTF_DIR) > /dev/null 2>&1
	@echo "printf generated"

$(MINILIBX):
	@make -C $(MINILIBX_DIR) > /dev/null 2>&1
	@echo "minilibx generated"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) clean > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) clean > /dev/null 2>&1
	@rm -f $(OBJS)
	@echo "Objects cleaned"

fclean: clean
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) fclean > /dev/null 2>&1
	@rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
