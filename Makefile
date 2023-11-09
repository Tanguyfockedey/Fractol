# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 18:30:38 by tafocked          #+#    #+#              #
#    Updated: 2023/11/09 19:10:00 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

FILES	= source/main.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LDLIBS	= includes/libft_updated/libft.a
OBJ		= $(FILES:.c=.o)

re: fclean $(NAME) clean

all: fclean libs $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

libs:
	@ $(MAKE) -C includes/libft_updated
	@ $(MAKE) -C includes/minilibx_opengl

clean:
	rm -f $(OBJ)
	$(MAKE) -C includes/libft_updated clean
	$(MAKE) -C includes/minilibx_opengl clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C includes/libft_updated fclean

.PHONY: all re libs clean fclean