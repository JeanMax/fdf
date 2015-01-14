#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/01/08 03:48:48 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRCC =  libft/libft.a main.c draw.c read.c hooks.c color.c

SRCO = zboub

FLAG =  -Wall -Wextra -Werror

.PHONY: all lib brute clean fclean re

all: $(NAME)

$(NAME):
	@rm -f $(NAME)
	@gcc $(FLAG) $(SRCC) -L/usr/X11/lib -lmlx -lXext -lX11 -o $(NAME)

lib:
	@cd libft; make re; cd ..

brute: lib all

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
