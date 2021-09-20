/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:08:04 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/20 16:56:53 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// void    ft_check_numbers(char **argv)
// {
//     int i;
//     int j;
//     int a;

//     i = 1;
//     while (argv[i])
//     {
//         j = 0;
//         if (argv[i][0] == '-')
//             j++;
//         while (argv[i][j])
//         {
//             if(!ft_isdigit((argv[i][j])))
//                 ft_error("NOT INTEGER\n");
//             j++;
//         }
//         a = ft_atoi(argv[i]);
//         if (a > 2147483647 || a < -2147483647)
//         {
//             ft_error("NOT INTEGER\n");
//         }
//         i++;
//     }
// }

// void    ft_check_duplicate(t_data *stack)
// {
//     int i;
//     int j ;

//     j = 0;
//     i = 0;
//     while (i <= stack->len_a)
//     {
//         j = 0;
        
//         while (j <= stack->len_a)
//         {
//             if (stack->a[i] == stack->a[j] && j != i)
//                 ft_error("error\n");
//             j++;
//         }
//         i++;
//     }
// }

// int     ft_check_sort(t_data *stack)
// {
//     int before;
//     int len;

//     len = stack->len_a;
//     if (len == 0)
//         return (1); 
//     while(len)
//     {   
//         before = len - 1;
//         if(stack->a[len] > stack->a[before])
//             len--;
//         if(stack->a[len] < stack->a[before])
//             return(1);
//     }
//     return(0);
// }