# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fokrober <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 15:30:34 by fokrober          #+#    #+#              #
#    Updated: 2020/02/07 00:13:48 by fokrober         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = viz

SRC = viz.c drawline.c ft_setup.c ft_hooks.c ft_key_hooks.c ft_mouse_hooks.c \
	  libviz.c
OBJ = $(SRC:.c=.o)


HEADER = viz.h
FTLIB = ../libft/libft.a

CM = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMWK = -lm -lmlx -framework OpenGL -framework AppKit

# =========================================================================== #

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(FTLIB)
	@$(CM) $(FRAMWK) $(OBJ) $(FTLIB) -o $(NAME)
	@echo "\033[1;32m↝ viz is compiled\033[0m"

$(FTLIB):
	make -C ../libft

clean:
	@rm -f $(OBJ)
	@echo "\033[1;32m↝ viz clean is done\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;32m↝ viz fclean is done\033[0m"

re: fclean all
