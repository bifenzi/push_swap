# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 16:48:06 by mbifenzi          #+#    #+#              #
#    Updated: 2021/10/05 00:48:33 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../push_swap

SRC = *.c

OBJECT = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJECT)
fclean: clean
	@rm -f $(NAME)
re: fclean all
