# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 16:48:06 by mbifenzi          #+#    #+#              #
#    Updated: 2021/04/19 16:52:48 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ../checker/*.c *.c 

OBJECT = *.o

NAME = push_swap.a

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@gcc push_swap.c $(NAME) -g #-fsanitize=address

bonus :
	@echo "hello world"

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

