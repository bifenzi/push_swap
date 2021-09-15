/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/15 18:50:55 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

int     ft_check_placements(t_data stack)
{
    int i = 0;
    int index_b;
    int index_a;
    int inst_a;
    int inst_b;
    int shortest;
    int a;
    int b;

    shortest = -1;
    while (*stack.len_b - 1 >= 0)
    {
        i = 0;
        while (i <= *stack.len_b - 1)
        {
            index_b = i;
            inst_b = smallest_b_instr(stack, index_b);
            index_a = smallest_a_index(stack, index_b);
            inst_a = smallest_a_instr(stack, index_a);
            //printf("a %d\n", index_a);
            if (smallest_b_instr(stack, index_b) == -1)
                index_b = *stack.len_b - 1 - index_b;
            if (smallest_a_instr(stack, index_a) == -1)
                index_a = *stack.len_a - index_a;
            if (shortest == -1)
            {
                shortest = index_a + index_b;
                a = index_a;
                b = index_b;
            }
            else if (shortest != -1 && index_a + index_b < shortest)
            {
                shortest = index_a + index_b;
                a = index_a;
                b = index_b;
            }
            i++;
            
        }
        b_to_a(stack, a, b, inst_a, inst_b);
        pa_instruction(stack);
    }
    return 0;
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
        //int j =0;
       /* while(j < *stack.len_a)
        {
            printf("stack a %d\n", stack.a[j]);
            j++;
        }*/
    }
    ft_check_placements(stack);
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