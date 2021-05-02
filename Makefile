# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/02 15:22:43 by mbifenzi          #+#    #+#              #
#    Updated: 2021/05/02 15:32:51 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	cd checker_files ; make
	cd push_swap_files ; make
clean :
	cd checker_files ; make clean
	cd push_swap_files ; make clean

fclean : 
	cd checker_files ; make fclean
	cd push_swap_files ; make fclean

re:
	cd checker_files ; make re
	cd push_swap_files ; make re