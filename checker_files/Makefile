
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

SRC = *.c

OBJECT = *.o

NAME = checker.a

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@gcc -o ./checker checker.c $(NAME) #-fsanitize=address

bonus :
	@echo "hello world"

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

