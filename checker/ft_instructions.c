/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.insts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:12:48 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/06 17:30:41 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int     ft_read_arguments(t_data stack)
{
    while (get_next_line(0, &stack.inst) > 0)
    {
        ft_instructions(stack);
        free(stack.inst);
        stack.inst = NULL;
    }
    return(1);
}

int      ss_instruction(t_data stack)
{
    int tmp;

    if(ft_strcmp(stack.inst, "sa") == 0 || ft_strcmp(stack.inst, "ss") == 0)
    {
        tmp = stack.a[0];
        stack.a[0] = stack.a[1];
        stack.a[1] = tmp;
    }
    if(ft_strcmp(stack.inst, "sb") == 0 || ft_strcmp(stack.inst, "ss") == 0)
    {
        tmp = stack.b[0];
        stack.b[0] = stack.b[1];
        stack.b[1] = tmp;
    }
    return(1);
}
int      rr_instruction(t_data stack, int len2)
{
    int tmp;

    if(ft_strcmp(stack.inst, "ra") == 0 || ft_strcmp(stack.inst, "rr") == 0)
    {
        int i;
        i = 0;
        tmp = stack.a[0];
        while(len2 > i)
        {
            stack.a[i] = stack.a[i + 1];
            i++;
        }
        stack.a[*stack.len_a] = tmp;
    }
    if(ft_strcmp(stack.inst, "rb") == 0 || ft_strcmp(stack.inst, "rr") == 0)
    {
        int i;
        i = 0;
        tmp = stack.b[0];
        while(len2 > i)
        {
            stack.b[i] = stack.b[i + 1];
            i++;
        }
        stack.b[*stack.len_b] = tmp;
    }
    return(1);
}
int      rrr_instruction(t_data stack, int len2)
{
    int tmp;
    len2 = *stack.len_a;
    if(ft_strcmp(stack.inst, "rra") == 0 || ft_strcmp(stack.inst, "rrr") == 0)
    {
        //printf("\n len2 %d\n", len2);
        //printf("\n len2 %d\n", stack.a[len2]);
        tmp = stack.a[*stack.len_a];
        
        while(len2 >= 0)
        {
            stack.a[len2] = stack.a[len2 - 1];
            len2--;
        }
        stack.a[0] = tmp;
    }
    len2 = *stack.len_b;
    if(ft_strcmp(stack.inst, "rrb") == 0 || ft_strcmp(stack.inst, "rrr") == 0)
    {
        
        tmp = stack.b[*stack.len_b - 1];
        while(len2 > 0)
        {
            stack.b[len2] = stack.b[len2 - 1];
            len2--;
        }
        stack.b[0] = tmp;
        
    }
    return(1);
}
int     
ft_instructions(t_data stack)
{
    int i;
    int len2;
    len2 = *stack.len_a;
    i = 0;
    if(ft_strcmp(stack.inst, "sa") == 0 || ft_strcmp(stack.inst, "sb") == 0 ||
        ft_strcmp(stack.inst, "ss") == 0)
        ss_instruction(stack);
    else if(ft_strcmp(stack.inst, "pa") == 0)
    {
        int b;
        int len_a;

        b = 0;
        len_a = *stack.len_a;
        //printf("\nlen_b %d\n", *stack.len_b);
       if (*stack.len_b)
       {
           
           *stack.len_a = *stack.len_a + 1 ;
           while (len_a > 0)
           {
                stack.a[len_a] = stack.a[len_a - 1];
                len_a--;
           }
           stack.a[0] = stack.b[0];
           *stack.len_b = *stack.len_b - 1;
           while (b < *stack.len_b )
           {
               stack.b[b] = stack.b[b + 1];
               b++;
           }
       }
       //printf("\n pa - > %d\n", stack.b[0]);
    }
    else if(ft_strcmp(stack.inst, "pb") == 0)
    {
        int a = 0;
        if (*stack.len_a)
        {
            
            len2 = *stack.len_b;
            while (len2 > 0)
            {
                stack.b[len2] = stack.b[len2 - 1];
                len2--;
            }
            stack.b[0] = stack.a[0];
            while (a < *stack.len_a)
           {
               stack.a[a] = stack.a[a + 1];
               a++;
           }
           *stack.len_a = *stack.len_a - 1;
           *stack.len_b = *stack.len_b + 1;
        }
    }

    else if(ft_strcmp(stack.inst, "ra") == 0 || ft_strcmp(stack.inst, "rb") == 0
            || ft_strcmp(stack.inst, "rr") == 0)
    {
        rr_instruction(stack, len2);
    }

    else if(ft_strcmp(stack.inst, "rra") == 0 || ft_strcmp(stack.inst, "rrb") == 0
            || ft_strcmp(stack.inst, "rrr") == 0)
    {
        rrr_instruction(stack, len2);
    }
        
    else if(ft_strcmp(stack.inst, "\n") == 0 || ft_strcmp(stack.inst, "\0") == 0 )
    {
        printf("success");
    }
    else
        ft_error("\nINVALID INSTRUCTION \n");
    i++;
    return(1);
}