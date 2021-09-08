/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/08 12:00:09 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_check_sort_b(t_data stack)
{
    int before;
    int len;
    if (*stack.len_b > 0)
        len = *stack.len_b - 1;
    else
        len = 0;
    while(len)
    {
        before = len - 1;
        if (stack.b[len] < stack.b[before])
            len--;
        else
            return(1);
    }
        return (0);  
}

int ft_stack_b(t_data stack,int len2)
{
    int j = 0;
    int k = 0;
    int l = 0;
    if (stack.b[1] > stack.b[0] && stack.a[1] < stack.a[0])
        ss_instruction(stack);
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        rr_instruction(stack, len2);    
    else if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        rrr_instruction(stack, len2);
    if (stack.b[1] > stack.b[0] && stack.a[1] > stack.a[0])
        sb_instruction(stack, l);
    if (stack.a[0] > stack.a[1] && stack.b[1] < stack.b[0])
        sa_instruction(stack, l);
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] > stack.a[0])
        rrb_instruction(stack, len2, k);
    else if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] > stack.a[0])
        rb_instruction(stack, len2, j);
    if (stack.b[*stack.len_b] < stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        rra_instruction(stack, len2, k);
    else if (stack.b[*stack.len_b] < stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        ra_instruction(stack, len2, j);
    return (len2);
}
int ft_stack_a(t_data stack, int len2)
{
    //printf("===>%d\n", stack.a[0]);
    //printf("stack_len===>%d\n", stack.a[*stack.len_a]);
    //printf("stack_0===>%d\n", stack.a[0]);
    //printf("leen===>%d\n",*stack.len_b);
    //printf("stack_len===>%d\n", stack.b[*stack.len_b]);
    //printf("stack_0===>%d\n", stack.b[0]);
    int j = 0;
    int k = 0;
    int l = 0;
    if (*stack.len_b)
    {
        if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] > stack.a[0])
            rrr_instruction(stack, len2);
        if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
            rr_instruction(stack, len2);
        if (stack.b[1] > stack.b[0] && stack.a[1] < stack.a[0])
            ss_instruction(stack);
    }
    if (stack.a[0] > stack.a[1])
        sa_instruction(stack, l);
    if (stack.a[*stack.len_a] < stack.a[0])
    {
        //write(1, "SSSSS", 5);
        rra_instruction(stack, len2, k);
    }
    else if (stack.a[*stack.len_a] < stack.a[0])
        ra_instruction(stack, len2, j);
    
    return(len2);
}        
int ft_loop(t_data stack, int len2)
{
    int j = 0;
    if (*stack.len_b > 1)
    {
        while(ft_check_sort_b(stack) &&
        stack.b[0] > stack.b[1] && stack.b[0] > stack.b[*stack.len_b])
        {
            pa_instruction(stack);
            if(*stack.len_a > 0 && stack.a[0] > stack.a[1] && stack.a[0] > stack.a[*stack.len_b])
                break ;
        }
        if(*stack.len_b)
        { 
            ft_stack_b(stack, len2);
        }
        ft_stack_a(stack, len2);
    }
    if (*stack.len_a>= 0 && ft_check_sort(stack))
    {
        while(ft_check_sort(stack) &&
        stack.a[0] < stack.a[1] && stack.a[0] < stack.a[*stack.len_a])
        {
            pb_instruction(stack, len2);
            if (stack.b[0] < stack.b[*stack.len_b])
            {
                if (stack.a[0] > stack.a[*stack.len_a])
                {
                    rrr_instruction(stack, len2);
                }
                else
                    rb_instruction(stack,len2,j);
            }
            
           if(*stack.len_b > 1 && stack.b[0] < stack.b[1] && stack.b[0] < stack.b[*stack.len_b])
                break ;
        }
        
        if (*stack.len_a)
        {
            //write(1, "TT", 2);
            ft_stack_a(stack,len2);
        }
        
    }
    return 0;
}
int ft_finish_him(t_data stack, int len2)
{
    pa_instruction(stack);
    ft_stack_a(stack, len2);
    if(stack.a[1] > stack.a[2] && *stack.len_a > 1 && *stack.len_b)
    {
        pb_instruction(stack, len2);
        ft_stack_a(stack, len2);
    }
    return 0;
}
int  ft_execute_sort(t_data stack)
{
    int len2;

    len2 = *stack.len_a;
    while (ft_check_sort(stack) || ft_check_sort_b(stack))
    {
        if (ft_check_sort(stack) || ft_check_sort_b(stack))
        {
            ft_loop(stack, len2);
        }
        if (!ft_check_sort(stack) && !ft_check_sort_b(stack))
        {
            while (*stack.len_b)
            {
                ft_finish_him(stack, len2);
            }
            break ;
        }
    }
    return 0;
}


int     main(int argc, char **argv)
{
    t_data stack;
    stack.a = malloc(sizeof(int) * (argc));
    stack.b = malloc(sizeof(int) *  (argc));
    stack.len_a = malloc(sizeof(int));
    stack.len_b = malloc(sizeof(int));
    *stack.len_a = argc - 2;
    *stack.len_b = 0;
    ft_read_arguments(stack, argv);
    ft_check_numbers(argv);
    ft_check_duplicate(stack);
    ft_execute_sort(stack);
    ft_free(stack);
    return (0);
}