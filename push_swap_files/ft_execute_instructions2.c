/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:22:22 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/06/21 18:38:07 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_instruction(t_data stack, int len2)
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
	ft_success("ra\n");
}

void	rb_instruction(t_data stack, int len2)
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
		ft_success("rb\n");
}
void    rra_instruction(t_data stack, int len2)
{
    int tmp;
    
    tmp = stack.a[*stack.len_a];

		while(len2 >= 0)
		{
			stack.a[len2] = stack.a[len2 - 1];
			len2--;
		}
		stack.a[0] = tmp;
			ft_success("rra\n");
}

void    rrb_instruction(t_data stack, int len2)
{
    int tmp;
    
    tmp = stack.b[*stack.len_b - 1];
	while(len2 > 0)
	{
		stack.b[len2] = stack.b[len2 - 1];
		len2--;
	}
	stack.b[0] = tmp;
		ft_success("rrb\n");
}
	
void ft_generate_instructions(t_data stack, int len2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (*stack.len_a >= 1)
    {
		