# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fokrober <robright28@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 15:30:34 by fokrober          #+#    #+#              #
#    Updated: 2020/02/21 01:28:33 by fokrober         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fokrober.filler

SRC = main.c parser.c get_token.c ft_heatmap.c ft_solve.c ft_sprintf.c \
	ft_print_token.c
OBJ = $(SRC:.c=.o)

HEADER = filler.h
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

# =========================================================================== #

all: depbuild $(NAME)

depbuild:
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(HEADER) 
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "\033[1;32m↝ filler is compiled\033[0m"

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@echo "\033[1;32m↝ clean is done\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[1;32m↝ fclean is done\033[0m"

re: fclean all
