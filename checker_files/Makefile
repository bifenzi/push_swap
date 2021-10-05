
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 14:33:22 by mbifenzi          #+#    #+#              #
#    Updated: 2019/11/05 15:47:48 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../checker

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
