# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 16:48:06 by mbifenzi          #+#    #+#              #
#    Updated: 2021/09/21 17:33:22 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = zyada.c ft_atoi.c ft_strcmp.c ft_execute_instructions.c ft_instructions.c \
		ft_execute_instructions2.c ft_a_to_be.c

OBJECT = *.o

NAME = push_swap.a

all : $(NAME)

$(NAME) :
	@gcc  -c -g $(SRC) -g -fsanitize=address
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@gcc push_swap.c $(NAME)

bonus :
	@echo "hello world"

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

