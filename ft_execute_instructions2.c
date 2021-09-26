/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:22:22 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/26 18:10:56 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_instruction(t_data *stack, int j)
{
	
	int tmp;
	int i;

	i = 0;
	tmp = stack->index[i];
	while(i < stack->len_a - 1)
	{
		stack->index[i] = stack->index[i + 1]; 
		i++;
	}
	stack->index[stack->len_a - 1] = tmp;
	if(j == 0)
		ft_success("ra\n");
}

void	rb_instruction(t_data *stack, int j)
{
	int tmp;
	int i;

	i = 0;
	tmp = stack->b[i];
	while(i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1]; 
		i++;
	}
	stack->b[stack->len_b - 1] = tmp;
	if(j == 0)
		ft_success("rb\n");
}

void    rra_instruction(t_data *stack, int k)
{
    int tmp;
    int len2 = stack->len_a;
    tmp = stack->index[stack->len_a - 1];

	while(len2 > 0)
	{
		stack->index[len2] = stack->index[len2 - 1];
		len2--;
	}
	stack->index[0] = tmp;
	if(k == 0)
		ft_success("rra\n");
}

void    rrb_instruction(t_data *stack, int k)
{
    int tmp;
    int len2 = stack->len_b;
    tmp = stack->b[stack->len_b - 1];
	while(len2 > 0)
	{
		stack->b[len2] = stack->b[len2 - 1];
		len2--;
	}
	stack->b[0] = tmp;
	if(k == 0)
		ft_success("rrb\n");
}