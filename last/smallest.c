/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:30:25 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/16 18:50:39 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     smallest_b_instr(t_data stack, int index_b)
{
    int moyenne;

    moyenne = *stack.len_b/2;
    if (index_b > moyenne)
        return(-1);
    else 
        return (1);
}
int     smallest_a_instr(t_data stack, int index_a)
{
    int moyenne;

    moyenne = *stack.len_a/2;
    if (index_a > moyenne)
        return(-1);
    else
        return (1);
}
int     smallest_a_index(t_data stack, int index_b)
{
    int i = 0;
    int ret;
    int compare;

    ret = 0;
    while (i <= *stack.len_a)
    {
        if (i == 0 && stack.a[i] - stack.b[index_b] > 0)
        {
            compare = stack.a[i] - stack.b[index_b];
            ret = 0;
        }
        else if (i > 0 && stack.a[i] - stack.b[index_b] > 0 && stack.a[i] - stack.b[index_b] < compare )
        {
            compare = stack.a[i] - stack.b[index_b];
            ret = i ;
        }  
        i++;
    }
    //printf("ret = %d\n", ret);
    return (ret);
}
int     b_to_a(t_data stack, int a, int b, int inst_a, int inst_b)
{
    int j;

    j = 0;
    if (inst_b == -1 && inst_a == -1)
    {
        while (a > 0 && b > 0)
        {
            rrr_instruction(stack);
            a--;
            b--;
        }
        
        while (a > 0)
        {
            
            rra_instruction(stack, j);
            a--;
        }
        while (b > 0)
        {
            rrb_instruction(stack, j);
            b--;
        }
    }
    else if (inst_b == 1 && inst_a == 1)
    {
        while (a > 0 && b > 0)
        {
        rr_instruction(stack);
        a--;
        b--;
        }
        while (a > 0)
        {
            ra_instruction(stack, j);
            a--;
        }
        while (b > 0)
        {
            rb_instruction(stack, j);
            b--;
        }
    }
    else if (inst_b == 1 && inst_a == -1)
    {
        while (a > 0)
        {
            rra_instruction(stack, j);
            a--;
        }
        while (b > 0)
        {
            rb_instruction(stack, j);
            b--;
        }
    }
    else if (inst_b == -1 && inst_a == 1)
    {
        while (a > 0)
        {
            ra_instruction(stack, j);
            a--;
        }
        while (b > 0)
        {
            rrb_instruction(stack, j);
            b--;
        }
    }
    return 0;
}