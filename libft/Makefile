# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fokrober <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 15:30:34 by fokrober          #+#    #+#              #
#    Updated: 2020/02/10 16:40:49 by fokrober         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isdigit.c ft_lstmap.c ft_memdel.c  ft_next_char.c ft_putnbr_fd.c \
	  ft_strdel.c   ft_strmapi.c  ft_strstr.c ft_atoi.c    ft_islower.c  \
	  ft_lstnew.c   ft_memdup.c   ft_push_char.c ft_putstr.c   ft_strdup.c \
	  ft_strncat.c  ft_strsub.c ft_atonbr.c   ft_isprint.c  ft_lstpush.c  \
	  ft_memdupz.c  ft_push_nbr.c  ft_putstr_fd.c ft_strequ.c   ft_strncmp.c \
	  ft_strtrim.c ft_bsize.c   ft_isupper.c  ft_lstset.c   ft_memichr.c \
	  ft_push_str.c  ft_realloc.c  ft_striter.c  ft_strncpy.c  ft_todigit.c \
	  ft_build_nbr.c ft_itoa.c    ft_memalloc.c  ft_memjoin.c  ft_putchar.c  \
	  ft_strcat.c   ft_striteri.c  ft_strnequ.c  ft_tolower.c \
	  ft_bzero.c   ft_lstadd.c   ft_memccpy.c  ft_memmove.c  \
	  ft_putchar_fd.c ft_strchr.c   ft_strjoin.c  ft_strnew.c   ft_toupper.c \
	  ft_isalnum.c  ft_lstdel.c   ft_memchr.c   ft_memset.c   ft_putendl.c  \
	  ft_strclr.c   ft_strlcat.c  ft_strnstr.c  get_next_line.c \
	  ft_isalpha.c  ft_lstdelone.c ft_memcmp.c   ft_nbrlen.c   ft_putendl_fd.c \
	  ft_strcmp.c   ft_strlen.c   ft_strrchr.c \
	  ft_isascii.c  ft_lstiter.c  ft_memcpy.c   \
	  ft_next_byte.c ft_putnbr.c   ft_strcpy.c   ft_strmap.c   ft_strsplit.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;34m↝ libft is compiled\033[0m"

%.o: %.c libft.h
	$(CC) $(CFLGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[1;34m↝ libft is clean\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34m↝ libft is fclean\033[0m"

re: fclean all
