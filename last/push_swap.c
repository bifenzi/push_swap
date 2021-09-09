/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/09 19:41:49 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sorted(t_data stack, t_sort the)
{
     int i = 1;
     int j = 0 ;
     int k = 0;
    while (stack.a[i])
    {
        if(stack.a[i] < stack.a[j])
            the.index[k] = i;
        j++;
    }
    k++;
    i++;
    while (stack.a[i])
    {
        if(stack.a[i] < stack.a[j] && stack.a[i] > stack.a[the.index[k]])
            the.index[k] = i;   
    }
    // sorted = malloc(sizeof(int) * sta)
}
void ft_execute_sort(t_data stack, t_sort the)
{

    ft_sorted(stack,the);
}
int     main(int argc, char **argv)
{
    t_data stack;
    t_sort the;
    the.moyenne = malloc(sizeof(int));
    stack.len_a = malloc(sizeof(int));
    stack.len_b = malloc(sizeof(int));
    *stack.len_a = argc - 2;
    *stack.len_b = 0;
    *the.moyenne = (argc - 2) / 2;    
    stack.a = malloc(sizeof(int) * (argc));
    stack.b = malloc(sizeof(int) *  (argc));
    ft_read_arguments(stack, argv);
    ft_check_numbers(argv);
    ft_check_duplicate(stack);
    ft_execute_sort(stack,the);
    ft_free(stack, the);
    return (0);
}