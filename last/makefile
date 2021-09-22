# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 16:48:06 by mbifenzi          #+#    #+#              #
#    Updated: 2021/09/22 15:16:38 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re


NAME = push_swap
NAME_BONUS = checker

SRC = push_swap.c zyada.c ft_atoi.c ft_strcmp.c ft_execute_instructions.c ft_instructions.c \
		ft_execute_instructions2.c ft_a_to_be.c
OBJECT = $(SRC:.c=.o)
#OBJECT_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) -g -fsanitize=address
	@echo "wlah ila goood"

#bonus:
#	@gcc -Wall -Wextra -Werror $(SRC_BONUS) -o $(NAME_BONUS)
#	@echo "🎁🎁🎁"

clean:
	@rm -f $(OBJECT)
	@echo "msa7 9lwa we7da"
fclean: clean
	@rm -f $(NAME)
	@echo "msa7 l9lawi kaaaaaml"
re: fclean all
