# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fokrober <robright28@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 15:30:34 by fokrober          #+#    #+#              #
#    Updated: 2020/02/22 02:55:47 by fokrober         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fokrober.filler
SRC = main.c parser.c get_token.c ft_heatmap.c ft_solve.c ft_sprintf.c
OBJ = $(SRC:.c=.o)
INCLUDE = filler.h
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

# =========================================================================== #

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(INCLUDE) 
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
