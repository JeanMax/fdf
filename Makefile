#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/01/19 11:39:25 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRCC =  libft/libft.a main.c draw.c read.c hooks.c color.c

SRCO = zboub

FLAG =  -Wall -Wextra -Werror

.PHONY: all lib soft clean fclean re

all: $(NAME)

$(NAME):
	@rm -f $(NAME)
	@cd libft; make re; cd ..
	@gcc $(FLAG) $(SRCC) -L/usr/X11/lib -lmlx -lXext -lX11 -o $(NAME) -lm

lib:
	@cd libft; make re; cd ..

soft:
	@rm -f $(NAME)
	@gcc $(FLAG) $(SRCC) -L/usr/X11/lib -lmlx -lXext -lX11 -o $(NAME) -lm

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
