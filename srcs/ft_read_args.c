/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:50:50 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/05/02 16:04:59 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_files/push_swap.h"

void    ft_args(char **argv)
{
    char *str;
    
    int i;
    int j;

    i = 1;
    j = 0;
    if(ft_strcmp(argv[i], "$ARG") == 0)
    {
        while (!ft_isdigit(argv[i][j]))
            i++;
    }
    
}