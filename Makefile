# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 18:30:38 by tafocked          #+#    #+#              #
#    Updated: 2023/11/09 16:09:04 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

FILES	= main.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror libraries/libft_updated/libft.a
OBJ		= $(FILES:.c=.o)

re: fclean $(NAME) clean

all: fclean libs $(NAME) clean

$(NAME): $(OBJ)
#	ar -r $(NAME) $(OBJ)

libs:
	@ $(MAKE) -C libraries/libft_updated
	@ $(MAKE) -C libraries/minilibx_opengl

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: