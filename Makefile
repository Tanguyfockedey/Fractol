# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 18:30:38 by tafocked          #+#    #+#              #
#    Updated: 2023/11/08 18:50:58 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

FILES	= 

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
OBJ		= $(FILES:.c=.o)

re: fclean $(NAME) clean

all: fclean libs $(NAME) clean

$(NAME): $(OBJ)
	ar -r $(NAME) $(OBJ)

libs:
	@ $(MAKE) -C libraries/libft_updated

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: