/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:30:25 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/18 19:17:03 by mbifenzi         ###   ########.fr       */
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
// int     dig_num(int *c)
// {
//     int i = 0;

//     while (c[i])
//         i++;
//     return i;
// }
int     smallest_a_index(t_data stack, int index_b, int *sorted)
{
    int i = 0;
    int pos;
    int j = 1;
    pos = ft_check_pos(stack.b[index_b], sorted);
    if (pos == 0)
    {
        return 0;
    }
    else if (pos == ft_strlen((char*)(sorted)))
    {
        return (*stack.len_a);
    }
    else
    {
        while (sorted[pos + j] != stack.a[i] && i <= *stack.len_a)
        {
            i++;
            if (stack.a[i] == sorted[pos + 1])
                return(i);
        }
            j++;
            
    }
    //while 
      
       // printf("%d --- %d\n",stack.b[index_b], i);  
    //printf("ret = %d\n", ret);
    return (i);
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
        //printf("stack a =%d --- index a = %d\n",stack.b[b], a);
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