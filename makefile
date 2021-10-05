# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 00:37:32 by mbifenzi          #+#    #+#              #
#    Updated: 2021/10/05 00:48:43 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	@cd ./push_swap_files ; make
clean :
	@cd ./checker_files ; make clean
	@cd ./push_swap_files ; make clean

fclean : 
	@cd ./checker_files ; make fclean
	@cd ./push_swap_files ; make fclean

re:
	@cd ./push_swap_files ; make re
bonus :
	@cd ./checker_files ; make re