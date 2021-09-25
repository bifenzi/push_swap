/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/25 18:31:38 by mbifenzi         ###   ########.fr       */
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
int     ft_check_sort(t_data *stack)
{
    int before;
    int len;

    len = 0;
    while(len < stack->len_a)
    {   
        before = len + 1;
        if(stack->index[len] > stack->index[before])
            return(0);
        len++;
    }
    return(1);
}
void    push_to_b(t_data *stack)
{
    int i;
    int k;
    int z;
    
    z = 0;
    i = 0;
    k = 0;


    while (!ft_check_sort(stack))
    {
        if (stack->index[i] >= k && stack->index[i] < k + 12)
        {
            k = stack->index[i];
            ra_instruction(stack, z);
        }
        else
            pb_instruction(stack);
    }  
}
void init_data(int *data)
{
    data[MINB] = 0;
    data[MINA] = 0;
    data[MINAB] = -1;
    data[INSTB] = 1;
    data[INSTA] = 1;
    data[MAX] = 0;
}

void    max_a(t_data *stack, int *data, int max)
{
    int i;

    i = 0;
    while (i < stack->len_a)
    {
        if (stack->index[i] == max)
        {
            data[CURRENTA] = i;
            break ;
        }
        i++;
    }
    data[MAX] = 1;
}

void    min_a(t_data *stack, int *data, int min)
{
    int i;

    i = 0;
    while (i < stack->len_a)
    {
        if (stack->index[i] == min)
        {
            data[CURRENTA] = i;
            break ;
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
        {
            data[CURRENTA] = i;
            break ;
        }
        i++;
    }
    
}

int    maximum(t_data *stack)
{
    int i;
    int max;

    max = 0;
    i = 0;
    while (i < stack->len_a)
    {
        if (max > stack->index[i])
            max = stack->index[i];
        i++;
    }
    return (max);
}
int    minimum(t_data *stack)
{
    int i;
    int min;

    min = 0;
    i = 0;
    while (i < stack->len_a)
    {
        if (min < stack->index[i])
            min = stack->index[i];
        i++;
    }
    return (min);
}
void     b_index_in_a(t_data *stack, int *data)
{
    if (data[CURRENTB] > maximum(stack))
        max_a(stack, data, maximum(stack));
    else if (data[CURRENTB] < minimum(stack))
        min_a(stack, data, minimum(stack));
    else
        mid_a(stack, data);
}

void ft_min(t_data *stack, int *data)
{
    int i;
    
    i = 0;
    while (i < stack->len_b)
    {
        data[CURRENTB] = i;
        if (stack->len_b == 1)
            init_data(data);
        b_index_in_a(stack, data);
        
        if (data[MINAB] == -1)
        {
            data[MINA] = data[CURRENTA];
            data[MINB] = data[CURRENTB];
            data[MINAB] = data[CURRENTA] + data[CURRENTB];
        }
        else if (data[CURRENTA] + data[CURRENTB] < data[MINAB])
        {
            data[MINAB] = data[CURRENTA] + data[CURRENTB];
            data[MINA] = data[CURRENTA];
            data[MINB] = data[CURRENTB];
        }   
        printf("------%d\n",data[MINA]);
        printf("------%d\n",data[MINB]);
        printf("------%d\n",data[MINAB]);   
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
        if (data[MAX] == 1)
            data[MINA] = stack->len_a + 2 - data[MINA];
        else
        {
            data[MINA] = stack->len_a + 1 - data[MINA];
        }
    }

        
    moyenne = stack->len_b/2;
    if (data[MINB] > moyenne)
    {
        data[INSTB] = 0;
        data[MINB] = stack->len_b - 1 - data[MINA];
    }
}

void    do_it(t_data *stack, int *data)
{
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
        //upside_down(stack, data);
        do_it(stack, data);
        pa_instruction(stack);
    }
}

void    final_touch(t_data *stack)
{
    int i;
    int moyenne;
    int k;
    
    k = 0;
    i = 0;
    moyenne = stack->len_a/2;
    while (i <= stack->len_a)
    {
        if (stack->index[i] == 0)
            break;
        i++;
    }
    if (i > moyenne)
    {
        while (i <= 0)
        {
            rra_instruction(stack, k);
            i--;
        }
    }
    else
    {
        while (i < 0)
        {
            ra_instruction(stack, k);
            i--;
        }
    }
    
}

int     main(int argc, char **argv)
{
    t_data *stack;

    stack = malloc(sizeof(t_data));
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
    push_to_a(stack);
    //final_touch(stack);
    int i = 0;
    while (i < argc - 1)
    {
        printf("index--%d\n", stack->index[i]);
        i++;
    }
    ft_free(stack);    
    return (0);
}