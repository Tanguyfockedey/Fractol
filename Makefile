# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 18:30:38 by tafocked          #+#    #+#              #
#    Updated: 2023/11/22 19:11:29 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

FILES	= source/main.c \
			source/msg.c \
			source/initialisation.c \
			source/hooks.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LDLIBS	= includes/libft_updated/libft.a \
			-lmlx -framework OpenGL -framework AppKit \
			-lm
OBJ		= $(FILES:.c=.o)

all: fclean libs $(NAME) clean

re: $(NAME)
 
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