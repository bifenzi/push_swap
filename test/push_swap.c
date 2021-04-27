/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/27 15:06:25 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int     ft_check_sort_b(t_data stack)
{
    int before;
    int len = *stack.len_b;
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
void    ft_stack_b(t_data stack, int len2)
{
    //printf("\nstack.b - - %d\n", stack.b[0]);
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] > stack.a[0])
        rrr_instruction(stack, len2);
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] > stack.a[0])
        rr_instruction(stack, len2);
    if (stack.b[1] > stack.b[0] && stack.a[1] < stack.a[0])
        ss_instruction(stack);
    
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        rrb_instruction(stack, len2);
    if (stack.b[*stack.len_b] < stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        rra_instruction(stack, len2);
    if (stack.b[1] > stack.b[0] && stack.a[1] < stack.a[0])
    {
       // printf("wawaawawaw");
       // printf("\nstack.b 0 - - %d\n", stack.b[0]);
        //printf("\nstack.b 1 - - %d\n", stack.b[1]);
        sb_instruction(stack);
    }
    if (stack.a[0] > stack.a[1] && stack.b[1] > stack.b[0])
    {
        //printf("\nstack 0--%d\n", stack.a[0]);
        //printf("\nstack 1--%d\n", stack.a[1]);
        sa_instruction(stack);
    }
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] > stack.a[0])
        rb_instruction(stack, len2);
    if (stack.b[*stack.len_b] < stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        ra_instruction(stack, len2);
}

int ft_execute_sort(t_data stack)
{
    int i;
    int len2;

    len2 = *stack.len_a;
    i = 0;
    while(ft_check_sort(stack) && i <= len2)
    {
        //printf("sasasasas");
       // break ;
        
        while (*stack.len_a >= 1)
        {
            if (*stack.len_b >= 1)
            {
                ft_stack_b(stack, len2);
            }
            if (stack.a[0] > stack.a[*stack.len_a])
                rra_instruction(stack, len2);
            if (stack.a[0] > stack.a[*stack.len_a])
                ra_instruction(stack, len2);
            if (stack.a[0] > stack.a[1])
                sa_instruction(stack);
            //printf("\nlen b == - - %d\n", *stack.len_b);
            if (ft_check_sort(stack) == 0 && *stack.len_b > 0 && ft_check_sort_b(stack) == 0)
            {
                //printf("\nstack.a - - %d\n", stack.a[0]);
                //printf("\nlen b == - - %d\n", *stack.len_b);
                while (*stack.len_b > 0)
                {
                    //printf("\nlen b == - - %d\n", *stack.len_b);
                    pa_instruction(stack);
                    //*stack.len_b = *stack.len_b - 1; 
                }
                //break ;
            }
            if (ft_check_sort(stack) == 1)
            {
                //write(1,"dddddd\n",6);
                pb_instruction(stack);
            }
            if (ft_check_sort(stack) == 0)
                break ;
        }
        i++;
    }
    return(0);
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
    //int i = 0;
    // while(i > *stack.len_a )
    // {
    //     printf("\nstaack.a = = %d\n", stack.a[i]);
    //     i++;
    // }
    return (0);
}