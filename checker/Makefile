
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

SRC = ft_atoi.c ft_strcmp.c checker.c get_next_line.c get_next_line_utils.c ft_instructions.c ft_isdigit.c \
		ft_check_errors.c ft_execute_instructions.c ft_execute_instructions2.c

OBJECT = *.o

NAME = checker.a

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@gcc checker.c $(NAME) -g #-fsanitize=address

bonus :
	@echo "hello world"

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

