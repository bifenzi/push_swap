/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/20 18:08:03 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int     ft_check_pos(int c, int *sorted)
{
    int pos;
    int i = 0;
    int j = 0;
   
    while (sorted[i])
    {
        if (c  == sorted[i])
        {
               return (i);
        }
        i++;
    }
    return(0);
}

void    ft_sort_table(t_data *stack)
{
    int i;
    int j;
    int tmp;
    i = 0;
    while (i <= stack->len_a)
    {
        stack->sorted[i] = stack->a[i];
        i++;
    }
    i = 0;
    while (i <= stack->len_a)
    {
        j = i + 1;
        while (j <= stack->len_a)
        {
            if (stack->sorted[i] > stack->sorted[j])
            {
                tmp = stack->sorted[i];
                stack->sorted[i] = stack->sorted[j];
                stack->sorted[j] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 0;
}

// int     ft_check_placements(t_data *stack, int *sorted)
// {
//     int i = 0;
//     int index_b;
//     int index_a;
//     int inst_a;
//     int inst_b;
//     int shortest;
//     int a;
//     int b;
//     int k;

//     shortest = -1;
//       i = 0;
//     while (stack->len_b - 1 >= 0)
//     {
//         i = 0;
//         while (i <= stack->len_b - 1)
//         {
//             index_b = i;
//             k = 0;
//             inst_b = smallest_b_instr(stack, index_b);
//             index_a = smallest_a_index(stack, index_b, sorted);
//             inst_a = smallest_a_instr(stack, index_a);
                
//             if (smallest_b_instr(stack, index_b) == -1)
//                 index_b = stack->len_b - 1 - index_b;
//             if (smallest_a_instr(stack, index_a) == -1)
//                     index_a = (stack->len_a + 1) - index_a;
            
//             if (shortest == -1)
//             {
//                 shortest = index_a + index_b;
//                 a = index_a;
//                 b = index_b;
//             }
//             else if (shortest != -1 && index_a + index_b < shortest && stack->len_b > 1)
//             {
//                 shortest = index_a + index_b;
//                 a = index_a;
//                 b = index_b;
//             }
//             else if (stack->len_b == 1 )
//             {
//                 a = index_a;
//                 b = index_b;
//             }
//             //printf("stack b =%d --- index b = %d\n",stack.b[i], a);
//             i++;
//         }
        
//         // printf("stack b = %d\n", stack.b[0]);
//         // printf("stack a = %d\n", stack.a[0]);
//         // printf("index a = %d\n", a);
//          //printf("index b = %d\n", b);
//         k = 0;
//         while(k <= *stack.len_a)
//         {
//             printf(" stack a = %d\n",stack.a[k]);
//             k++;
//         }
//         printf("index a = %d\n", a);
//         k = 0;
//         while(k <= *stack.len_b - 1)
//         {
//             printf(" stack b ==== %d\n",stack.b[k]);
//             k++;
//         }
//         b_to_a(stack, a, b, inst_a, inst_b);
//         pa_instruction(stack);
//     }
    
    // i = 0;
    // int j = 0;
    //     while(i < *stack.len_a)
    //     {
    //         if (stack.a[i] == sorted[0])
    //             break ;
    //         i++;
    //     }
    //     while (stack.a[0] != sorted[0])
    //     {
    //         if ( i >= *stack.len_a/2)
    //             ra_instruction(stack, j);
    //         else if ( i <= *stack.len_a/2)
    //             rra_instruction(stack, j);
    //     }
        // i = 0;
        // while(i <= *stack.len_a)
        // {
        //     printf("stack a = %d\n", stack.a[i]);
        //     i++;
        // }
//          k = 0;
//         while(k <= *stack.len_a)
//         {
//             printf(" stack a = %d\n",stack.a[k]);
//             k++;
//         }
//      return 0;
// }

int    ft_execute_sort(t_data *stack)
{
    int h;
    int i;
    int j;
    int pos;
    int min;
    int e;
    
    i = 0;
    h = 12;
    e = stack->len_a + 1;
    while (e--)
    {
        pos = ft_check_pos(stack->a[0], stack->sorted);
       // printf("%d ---------%d\n",stack.a[0],pos);
        if(pos >= i && pos <= h)
        {
            i += pos;
            h += pos;
            ra_instruction(stack, j);
        }
        else
            pb_instruction(stack);
//         //int j =0;
//        /* while(j < *stack.len_a)
//         {
//             printf("stack a %d\n", stack.a[j]);
//             j++;
//         }*/
//     }
//     //printf("%d ---------%d\n",stack.a[0],pos);
//     /*j = 0;
//        while(j <= *stack.len_a)
//         {
//             printf("stack a %d\n", stack.a[j]);
//             j++;
//     }
//     printf("-------------------------b----------\n");
//      j = 0;  
//       while(j < *stack.len_b)
//         {
//             printf("stack b %d\n", stack.b[j]);
//             j++;
//         }*/
    
// //     ft_check_placements(stack, sorted);
    }
    return 0;  
}
int     ft_check_number(char *str)
{
    if (*(str + 1) != '\0' && (*str == '+' || *str == '-'))
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

long long	ft_overflowhelper(char *str)
{
	long long	a;
	long		sign;

	a = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		str++;
		sign = (-1);
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	if (a < 0 && sign < 0)
		return (0);
	if (a < 0 && sign > 0)
		return (-1);
	return (a * sign);
}

int	check_overflow(char *str)
{
	long long	r;

	r = ft_overflowhelper(str);
	if (ft_strlen(str) > 15)
		return (1);
	if (r > 2147483647 || r < -2147483648)
		return (1);
	return (0);
}

int     ft_check_duplicate(int ac, char **av)
{
    int i; 
    int j;

    i = 1;
    j = 0;
    while (i < ac)
    {
        if (ft_check_number(av[i]) || check_overflow(av[i]))
            return (1);
        j = i + 1;
        while (j < ac)
        {
            if (ft_strcmp(av[i], av[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
void    ft_remplir(t_data *stack, int ac, char **av)
{
    if (ft_check_duplicate(ac, av))
        ft_error("error\n");
    else
        ft_read_arguments(stack ,av);
}

int     main(int argc, char **argv)
{
    t_data *stack;
    

    stack = malloc(sizeof(t_data));
    // stack.len_a = malloc(sizeof(int));
    // stack.len_b = malloc(sizeof(int));
    stack->len_a = argc - 2;
    stack->len_b = 0;
    stack->a = malloc(sizeof(int) * (argc));
    stack->b = malloc(sizeof(int) *  (argc));
    stack->sorted = malloc(sizeof(int) * (argc));
    ft_remplir(stack, argc, argv);
    ft_sort_table(stack);
    ft_execute_sort(stack);
    // ft_free(stack, sorted);
    return (0);
}
    // int i = 0;
    // while (i < argc - 1)
    // {
    //     printf("%d\n", stack->a[i]);
    //     i++;
    // }