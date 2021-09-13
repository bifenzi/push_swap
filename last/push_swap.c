/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/13 17:54:24 by mbifenzi         ###   ########.fr       */
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
int     ft_smallest_b(t_data stack)
{
    int i;
    int j;
    int min;
    
    i = 0;
    j = 0;
    min = 0;
    while (i <= *stack.len_b - 1)
    {
        if (stack.b[i] < stack.b[min])
           min = i ;
        i++;
    }
    //printf("%d\n",min);
    return(min);
}
int         ft_min_b(t_data stack)
{
    int moyenne;
    int min;
    int i = 0;
    int j;

    j = 0;
    int k = 0;
    min = -1;
    moyenne = *stack.len_b/2;
    int *b = malloc((*stack.len_b + 1) * sizeof(int));
    while (i <= *stack.len_b - 1)
    {

        k = 0;
        while (k <= *stack.len_a)
        {
            if (stack.a[k] < stack.b[i])
                k++;
        }
        if (i > moyenne)
            b[i] = *stack.len_b - i  +k;
        else
            b[i] = i + k;
        i++;
    }
    b = ft_sort_table(b);
    i = b[0];
    free(b);
    return i;
}
int     ft_apply_pa(t_data stack, int min)
{
    int i = 0;
    int j = 0;
    if (stack.b[min] > stack.a[i])
    {
        while (stack.b[min] > stack.a[i] && i <= *stack.len_a)
        {
            i++;
        }
    }
    else if (stack.b[min] < stack.a[i])
    {
        i = 0;
         while (stack.b[min] < stack.a[i] && i <= *stack.len_a)
        {
            i++;
        }
    }
    
}
int    ft_execute_sort(t_data stack, int *sorted)
{
    int h;
    int i;
    int j;
    int pos;
    int min;
    
    i = 0;
    h = 12;
    while (*stack.len_a && ft_check_sort(stack))
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
    }
    min = ft_min_b(stack);
    ft_apply_pa(stack , min);
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
    ft_free(stack, sorted);
    return (0);
}