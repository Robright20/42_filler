# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fokrober <robright28@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 12:39:55 by ielouazz          #+#    #+#              #
#    Updated: 2020/02/26 12:42:50 by fokrober         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = draw_line.c ft_hooks.c get_map_info.c main.c store_point.c ft_filler.c \
	 ft_update.c 
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lm -lmlx -lft
LDFLAGS = -L$(LIBFT_DIR) -framework Appkit -framework OpenGl
HEADER = fdf.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(HEADER)
	gcc $(CFLAGS) $(OBJ) $(LDLIBS) $(LDFLAGS) -o $(NAME)

%.o:%.c $(HEADER)
	gcc $(CFLAGS) -c $<

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all	
