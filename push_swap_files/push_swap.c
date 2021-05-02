/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/05/02 15:49:56 by mbifenzi         ###   ########.fr       */
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
    int i = 0;
    int  j = 0;
    int k = 0;
    //printf("\nstack.b - - %d\n", stack.b[0]);
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] > stack.a[0])
        rrr_instruction(stack, len2);
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        rr_instruction(stack, len2);
    if (stack.b[1] > stack.b[0] && stack.a[1] < stack.a[0])
        ss_instruction(stack);
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] > stack.a[0])
        rrb_instruction(stack, len2, j);
    if (stack.b[*stack.len_b] < stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        rra_instruction(stack, len2, j);
    if (stack.b[1] > stack.b[0] && stack.a[1] > stack.a[0])
        sb_instruction(stack, i);
    if (stack.a[0] > stack.a[1] && stack.b[1] < stack.b[0])
        sa_instruction(stack, i);
    if (stack.b[*stack.len_b] > stack.b[0] && stack.a[*stack.len_a] > stack.a[0])
        rb_instruction(stack, len2, k);
    if (stack.b[*stack.len_b] < stack.b[0] && stack.a[*stack.len_a] < stack.a[0])
        ra_instruction(stack, len2, k);
}

int ft_execute_sort(t_data stack)
{
    int i;
    int j;
    int k;
    int len2;

    len2 = *stack.len_a;
    i = 0;
    j = 0;
    k = 0;
    while(ft_check_sort(stack))
        ft_generate_instructions(stack, len2);
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
    ft_args(argv);
    ft_check_numbers(argv);
    ft_check_duplicate(stack);
    ft_execute_sort(stack);
    ft_free(stack);
    return (0);
}