/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_be.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:24:22 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/24 16:52:23 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    b_to_a(t_data *stack, int *data)
{
    int j;
    
    j = 0;
    if (data[INSTA] == 1 && data[INSTA] == 1)
    {
        
        while (data[MINA] > 0 && data[MINB] > 0)
        {
            rr_instruction(stack);
            if(data[MINA] == 0 || data[MINB] == 0)
                break ;
            data[MINA] = data[MINA] - 1;
            data[MINB] = data[MINB] - 1;
        }
        while (data[MINA] > 0)
        {
            data[MINA] = data[MINA] - 1;
            ra_instruction(stack,j);
        }
        while (data[MINB] > 0)
        {
            data[MINB] = data[MINB] - 1;
            rb_instruction(stack,j);
        }    
    }
}

void    b_to_a2(t_data *stack, int *data)
{
    int j;

    j = 0;
    if (data[INSTA] == 0 && data[INSTB] == 0)
    {
        while (data[MINA] >= 0 && data[MINB] > 0)
        {
            rrr_instruction(stack);
            if(data[MINA] == 0 && data[MINB] == 0)
                    break ;
            data[MINA] = data[MINA] - 1;
            data[MINB] = data[MINB] - 1;
        }
        while (data[MINA] >= 0)
        {
            rra_instruction(stack, j);
            data[MINA] = data[MINA] - 1;
        }
        while (data[MINB] > 0)
        {
            rrb_instruction(stack, j);
            data[MINB] = data[MINB] - 1;
        }
    }
}

void    b_to_a3(t_data *stack, int *data)
{
    int j;

    j = 0;
    if (data[INSTA] == 1 && data[INSTB] == 0)
    {
        while (data[MINA] > 0)
        {
            ra_instruction(stack, j);
            data[MINA] = data[MINA] - 1;
        }
        while (data[MINB] > 0)
        {
            rrb_instruction(stack, j);
            data[MINB] = data[MINB] - 1;
        }
    }
}

void    b_to_a4(t_data *stack, int *data)
{
    int j;

    j = 0;
    if (data[INSTA] == 0 && data[INSTB] == 1)
    {
        while (data[MINA] >= 0)
        {
            rra_instruction(stack, j);
            data[MINA] = data[MINA] - 1;
        }
        while (data[MINB] > 0)
        {
            rb_instruction(stack, j);
            data[MINB] = data[MINB] - 1;
        }
    }
}