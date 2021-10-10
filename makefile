# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 17:51:21 by mbifenzi          #+#    #+#              #
#    Updated: 2021/10/08 12:35:17 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

SRC =	push_swap_files/b_to_a.c \
		push_swap_files/b_to_a1.c \
		push_swap_files/b_to_a2.c \
		push_swap_files/check_errors.c \
		push_swap_files/ft_atoi.c \
		push_swap_files/ft_execute_instructions.c \
		push_swap_files/ft_execute_instructions2.c \
		push_swap_files/ft_isdigit.c \
		push_swap_files/ft_sort3.c \
		push_swap_files/ft_strcmp.c \
		push_swap_files/push_swap.c \
		push_swap_files/remplissage.c \
		push_swap_files/zyada.c \
		push_swap_files/ft_instructions.c 

BONUS_SRC = checker_files/checker.c \
			checker_files/ft_atoi.c \
			checker_files/ft_check_errors.c \
			checker_files/ft_execute_instructions.c \
			checker_files/ft_execute_instructions2.c \
			checker_files/ft_instructions.c \
			checker_files/ft_isdigit.c \
			checker_files/ft_strcmp.c \
			checker_files/get_next_line.c \
			checker_files/get_next_line_utils.c \
			checker_files/instructions.c \
			checker_files/remplissage.c \



all : $(NAME)

bonus_all : $(BONUS_NAME)

$(NAME): $(SRC)
		@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)
$(BONUS_NAME):
		@gcc -Wall -Wextra -Werror $(BONUS_SRC) -o $(BONUS_NAME)

clean:
	@rm -f $(OBJECT)
bonus_clean:
	@rm -f $(BONUS_OBJECT)
fclean: clean
	@rm -f $(NAME)
bonus_fclean: clean
	@rm -f $(BONUS_NAME)
re: fclean all
bonus_re : bonus_fclean bonus_all