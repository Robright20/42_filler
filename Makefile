# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fokrober <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 15:30:34 by fokrober          #+#    #+#              #
#    Updated: 2020/02/01 11:33:41 by fokrober         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fokrober.filler

SRC = main.c
OBJ = $(SRC:.c=.o)


HEADER = filler.h
FTLIB = libft/libft.a

CM = gcc
CFLAGS = -Wall -Wextra -Werror 

# =========================================================================== #

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(FTLIB)
	@$(CM) $(FRAMWK) $(OBJ) $(FTLIB) -o $(NAME)
	@echo "\033[1;32m↝ filler is compiled\033[0m"

$(FTLIB):
	make -C libft

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@echo "\033[1;32m↝ clean is done\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "\033[1;32m↝ fclean is done\033[0m"

re: fclean all
