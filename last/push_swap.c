/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/22 16:40:14 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int     ft_check_pos(int c, int *sorted)
{
    // int pos;
    int i = 0;
    // int j = 0;
   
    while (sorted[i])
    {
        if (c  == sorted[i])
            return (i);
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

// int     ft_check_placements(t_data *stack)
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
//             index_a = smallest_a_index(stack, index_b);
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
//         while(k <= stack->len_a)
//         {
//             printf(" stack a = %d\n",stack->a[k]);
//             k++;
//         }
//         printf("index a = %d\n", a);
//         k = 0;
//         while(k <= stack->len_b - 1)
//         {
//             printf(" stack b ==== %d\n",stack->b[k]);
//             k++;
//         }
//         b_to_a(stack, a, b, inst_a, inst_b);
//         pa_instruction(stack);
//     }
    
//     i = 0;
//     int j = 0;
//         while(i < stack->len_a)
//         {
//             if (stack->a[i] == stack->sorted[0])
//                 break ;
//             i++;
//         }
//         while (stack->a[0] != stack->sorted[0])
//         {
//             if ( i >= stack->len_a/2)
//                 ra_instruction(stack, j);
//             else if ( i <= stack->len_a/2)
//                 rra_instruction(stack, j);
//         }
//         i = 0;
//         while(i <= stack->len_a)
//         {
//             printf("stack a = %d\n", stack->a[i]);
//             i++;
//         }
//          k = 0;
//         while(k <= stack->len_a)
//         {
//             printf(" stack a = %d\n",stack->a[k]);
//             k++;
//         }
//      return 0;
// }

// int    ft_execute_sort(t_data *stack)
// {
//     int h;
//     int i;
//     int j;
//     int pos;
//     int min;
//     int e;
    
//     i = 0;
//     h = 12;
//     e = stack->len_a + 1;
//     while (e--)
//     {
//         pos = ft_check_pos(stack->a[0], stack->sorted);
//        // printf("%d ---------%d\n",stack->a[0],pos);
//         if(pos >= i && pos <= h)
//         {
//             i += pos;
//             h += pos;
//             ra_instruction(stack, j);
//         }
//         else
//             pb_instruction(stack);
// //         //int j =0;
// //        /* while(j < *stack.len_a)
// //         {
// //             printf("stack a %d\n", stack.a[j]);
// //             j++;
// //         }*/
// //     }
// //     //printf("%d ---------%d\n",stack.a[0],pos);
// //     /*j = 0;
// //        while(j <= *stack.len_a)
// //         {
// //             printf("stack a %d\n", stack.a[j]);
// //             j++;
// //     }
// //     printf("-------------------------b----------\n");
// //      j = 0;  
// //       while(j < *stack.len_b)
// //         {
// //             printf("stack b %d\n", stack.b[j]);
// //             j++;
// //         }*/
    
//     ft_check_placements(stack);
//     }
//     return 0;  
// }
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

void    fillindex(t_data *stack)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i <= stack->len_a)
    {
        j = 0;
        while (stack->a[i] != stack->sorted[j])
            j++;
        stack->index[i] = j;
        i++;
    }
}
int     ft_check_sort(int *values)
{
    int before;
    int len;

    len = 0;
    while (values[len])
        len++;
    len--;
    // if (len == 0)
    //     return (1); 
    while(len)
    {   
        before = len - 1;
        if(values[len] > values[before])
            len--;
        if(values[len] < values[before])
            return(1);
    }
    return(0);
}
void    push_to_b(t_data *stack)
{
    int i;
    int j;
    int k;
    int z;
    
    z = 0;
    i = 0;
    j = 12;
    k = 0;
    while (ft_check_sort(stack->index))
    {
        if (stack->index[i] > k && stack->index[i] < j)
        {
            ra_instruction(stack, z);
            k += stack->index[i];
            j += stack->index[i];
        }
        else
            pb_instruction(stack);
        i++;
    }  
}
void init_data(int *data)
{
    data[MINB] = 0;
    data[MINA] = 0;
    data[MINAB] = -1;
    data[INSTB] = 1;
    data[INSTA] = 1;
}

void    max_a(t_data *stack, int *data)
{
    int i;
    int j;

    i = 0;
    while (i < stack->len_a)
    {
        j = i + 1;
        while (j < stack->len_a)
        {
            if (stack->index[i] < stack->index[j])
                data[CURRENTA] = j;
            j++;
        }
        i++;
    }
}

void    min_a(t_data *stack, int *data)
{
    int i;
    int j;

    i = 0;
    while (i <= stack->len_a)
    {
        j = i + 1;
        while (j <= stack->len_a)
        {
            if (stack->index[i] < stack->index[j])
                data[CURRENTA] = j;
            j++;
        }
        i++;
    }
}

void    mid_a(t_data *stack, int *data)
{
    int i;
    
    i = 1;

    while (i <= stack->len_a)
    {
        if(data[CURRENTB] > stack->index[i - 1] && data[CURRENTB] < stack->index[i])
            data[CURRENTA] = i;
        i++;
    }
    
}
void     b_index_in_a(t_data *stack, int *data)
{
    int i;
    int max;
    
    max = 0;
    i = 0;
    
    if (data[CURRENTB] == stack->max_len)
    { 
        max_a(stack,data);
    }
    else if (data[CURRENTB] == 0)
    {
        min_a(stack, data);
    }
        
    else
    {
        mid_a(stack, data);
    }
}

void ft_min(t_data *stack, int *data)
{
    int i;
    // int a;
    // int b;
    
    i = 0;
    while (i <= stack->len_b - 1)
    {
        data[CURRENTB] = stack->b[i];
        b_index_in_a(stack, data);
        if (data[MINAB] == -1)
        {
            data[MINA] = data[CURRENTA];
            data[MINB] = data[CURRENTB];
        }
        else if (data[CURRENTA] + data[CURRENTB] < data[MINAB])
        {
            data[MINAB] = data[CURRENTA] + data[CURRENTB];
            data[MINA] = data[CURRENTA];
            data[MINB] = data[CURRENTB];
        }
        i++;
    }
}
void    upside_down(t_data *stack, int *data)
{
    int moyenne;

    moyenne = stack->len_a/2;
    if (data[MINA] > moyenne)
    {
        data[INSTA] = 0;
        data[MINA] = stack->len_a + 1 - data[MINA];
    }
        
        
    moyenne = stack->len_b/2;
    if (data[MINB] > moyenne)
    {
        data[INSTB] = 0;
        data[MINB] = stack->len_b - data[MINA];
    }
        
}

void    do_it(t_data *stack, int *data)
{
    // int i;
    // int j;

    b_to_a(stack,data);
    b_to_a2(stack, data);
    b_to_a3(stack, data);
    b_to_a4(stack, data);
}
void    push_to_a(t_data *stack)
{
    // int i;
    // int j;
    int data[7];
    while (stack->len_b != 0)
    {
        init_data(data);
        ft_min(stack, data);
        // printf(" -- - - %d\n", data[MINA]);
        upside_down(stack, data);
        do_it(stack, data);
        pa_instruction(stack);
    }
}
int     main(int argc, char **argv)
{
    t_data *stack;
    

    stack = malloc(sizeof(t_data));
    // stack.len_a = malloc(sizeof(int));
    // stack.len_b = malloc(sizeof(int));
    stack->len_a = argc - 2;
    stack->len_b = 0;
    stack->max_len = argc - 2;
    stack->a = malloc(sizeof(int) * (argc));
    stack->b = malloc(sizeof(int) *  (argc));
    stack->sorted = malloc(sizeof(int) * (argc));
    stack->index = malloc(sizeof(int) * (argc));
    ft_remplir(stack, argc, argv);
    ft_sort_table(stack);
    fillindex(stack);
    push_to_b(stack);
    // push_to_a(stack);
    // ft_free(stack);    
    return (0);
}
    // i = 0;
    // while (i < argc - 1)
    // {
    //     printf("index--%d\n", stack->index[i]);
    //     i++;
    // }