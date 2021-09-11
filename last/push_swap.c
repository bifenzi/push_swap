/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/11 18:50:05 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_sort_table(int *a)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (a[i])
    {
        j = i + 1;
        while (a[j])
        {
            if (a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return a;
}
int     ft_check_pos(t_data stack, int *sorted)
{
    int pos;
    int i = 0;
    int j = 0;
   
    while (sorted[i])
    {
        if (stack.a[0] == sorted[i])
        {
               return (i);
        }
        i++;
    }
    return(0);
}
int    ft_execute_sort(t_data stack, int *sorted)
{
    int h;
    int i;
    int j;
    int e;
    int pos;
    
    i = 0;
    h = 12;
    e = 0;
    while (*stack.len_a && e <= 6)
    {
        pos = ft_check_pos(stack, sorted);
        if(pos >= i && pos <= h)
        {

            i += pos;
            h += pos;
            ra_instruction(stack, j);
            
        }
        else
            pb_instruction(stack);
        e++;
    }
    return 0;
}

int     main(int argc, char **argv)
{
    t_data stack;
    int *sorted;

    stack.len_a = malloc(sizeof(int));
    stack.len_b = malloc(sizeof(int));
    *stack.len_a = argc - 2;
    *stack.len_b = 0;
    stack.a = malloc(sizeof(int) * (argc));
    stack.b = malloc(sizeof(int) *  (argc));
    sorted = malloc(sizeof(int) * (argc));
    sorted = ft_read_arguments(stack,sorted ,argv);
    ft_check_numbers(argv);
    ft_check_duplicate(stack);
    sorted = ft_sort_table(sorted);
    ft_execute_sort(stack,sorted);
    ft_free(stack);
    return (0);
}