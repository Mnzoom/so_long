# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 12:10:54 by cn-goie           #+#    #+#              #
#    Updated: 2025/12/04 13:10:13 by cn-goie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
FLAGS		= -Wall -Wextra -Werror -Iinc -I$(LIBFT_DIR)

NAME		= libftprintf.a

SRCS		= ft_printf.c ft_printf_utils.c
OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)


$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re