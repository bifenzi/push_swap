/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/07/01 17:41:22 by mbifenzi         ###   ########.fr       */
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

int  ft_execute_sort(t_data stack, t_sort the)
{
    int j = 0;

    *the.moyenne = *stack.len_a/2;

// int f = 0;
//         //printf("-----\n");
//         while (f <= *stack.len_a)
//         {
//             printf("stack a de %d is %d\n",f,  stack.a[f]);
//             f++;
//         }
    while (ft_check_sort(stack) && *stack.len_a)
    {
        ft_9elleb(stack, the);
        //printf("the.one ( %d\n", *the.one);
        //printf("the.len == %d\n", *stack.len_a);
        while (stack.a[0] != *the.first && *stack.len_a && ft_check_sort(stack))
        {
            if (stack.a[0] > stack.a[1])
                sa_instruction(stack, j, the);
            if (*the.moyenne > *the.one && stack.a[0] != *the.first)
                ra_instruction(stack, j, the);
            else if (*the.moyenne <= *the.one && stack.a[0] != *the.first)
                rra_instruction(stack,j,the);
        }   
        if (*the.one == 0 && *stack.len_a > 1 && ft_check_sort(stack))
            pb_instruction(stack,the);
        //printf("le 1 is --%d\n", *the.first);

        // int f = 0;
        // //printf("-----\n");
        // while (stack.a[f]!= '\0' && f <= *stack.len_a)
        // {
        //     printf("stack a de %d is %d\n",f,  stack.a[f]);
        //     f++;
        // }
    }
    while (!ft_check_sort(stack) && !ft_check_sort_b(stack) && *stack.len_b)
        {
            pa_instruction(stack, the);
        }
        
    return 0;
}


int     main(int argc, char **argv)
{
    t_data stack;
    t_sort the;
    
    the.moyenne = malloc(sizeof(int));
    the.first = malloc(sizeof(int));
    the.one = malloc(sizeof(int));
    stack.len_a = malloc(sizeof(int));
    stack.len_b = malloc(sizeof(int));
    *stack.len_a = argc - 2;
    *stack.len_b = 0;
    *the.moyenne = (argc - 2) / 2;
    //ft_allocate(stack, the, argc);
    //printf("===> %s\n", argv[0]);
    // if (ft_strcmp(argv[1]," $ARG") == 0)
    // {
    //     printf("ssssss\n");
    //     stack.a = malloc(sizeof(int) * (ft_strlen(argv[0]) - 4));
    //     stack.b = malloc(sizeof(int) * (ft_strlen(argv[0]) - 4));
    //     ft_args(stack, argv); 
    // }
    // else
    // {
            
        stack.a = malloc(sizeof(int) * (argc));
        stack.b = malloc(sizeof(int) *  (argc));
        ft_read_arguments(stack, argv);
   // }
    ft_check_numbers(argv);
    ft_check_duplicate(stack);
    ft_execute_sort(stack,the);
    ft_free(stack, the);
    return (0);
}