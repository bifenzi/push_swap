/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:22:22 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/05/02 13:44:52 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_instruction(t_data stack, int len2, int k)
{
	
	int tmp;
	int i;
	i = 0;
	tmp = *stack.a;
	while(len2 > i)
	{
		stack.a[i] = stack.a[i + 1];
		i++;
	}
	stack.a[*stack.len_a] = tmp;
	if (k != 1)
		ft_success("ra\n");
}

void	rb_instruction(t_data stack, int len2, int k)
{
	int tmp;
	int i;
	i = 0;
	tmp = stack.b[0];	
	while(len2 > i)
	{
		stack.b[i] = stack.b[i + 1];
		i++;
	}
	stack.b[*stack.len_b] = tmp;
	if (k != 1)
		ft_success("rb\n");
}
void    rra_instruction(t_data stack, int len2, int j)
{
    int tmp;
    
    tmp = stack.a[*stack.len_a];

		while(len2 >= 0)
		{
			stack.a[len2] = stack.a[len2 - 1];
			len2--;
		}
		stack.a[0] = tmp;
		if (j != 1)
			ft_success("rra\n");
}

void    rrb_instruction(t_data stack, int len2, int j)
{
    int tmp;
    
    tmp = stack.b[*stack.len_b - 1];
	while(len2 > 0)
	{
		stack.b[len2] = stack.b[len2 - 1];
		len2--;
	}
	stack.b[0] = tmp;
	if (j != 1)
		ft_success("rrb\n");
}

void	ft_pa_instruction(t_data  stack, int len2)
{
	int i = 0;
	 if (*stack.len_b > 0 && ft_check_sort_b(stack) == 1)
		ft_stack_b(stack, len2);
	
	if (ft_check_sort(stack) == 0 && *stack.len_b > 0 && ft_check_sort_b(stack) == 0)
    {
		//printf("SSSSS");
        while (*stack.len_b > 0)
		{
            pa_instruction(stack);
			if (stack.a[0] > stack.a[1])
                sa_instruction(stack, i);
		}
    }
			
}

void ft_generate_instructions(t_data stack, int len2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (*stack.len_a >= 1)
        {
            if (*stack.len_b >= 1)
                ft_stack_b(stack, len2);
            if (stack.a[0] > stack.a[*stack.len_a])
                rra_instruction(stack, len2, j);
            if (stack.a[0] > stack.a[*stack.len_a] && stack.a[0] > stack.a[1])
            {
                if (stack.a[0] > stack.a[1])
                    sa_instruction(stack, i);
                ra_instruction(stack, len2, k);
            } 
            if (stack.a[0] > stack.a[1])
                sa_instruction(stack, i);
            ft_pa_instruction(stack, len2);
            if (ft_check_sort(stack) == 1)
                pb_instruction(stack);
            if (ft_check_sort(stack) == 0)
                break ;
        }
}