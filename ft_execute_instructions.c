/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:52 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/26 18:07:22 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_instruction(t_data *stack)
{
	int	b;
	int	len_a;

	b = 0;
	stack->len_a = stack->len_a + 1;
	len_a = stack->len_a;
	while (len_a > 0)
	{
		stack->index[len_a] = stack->index[len_a - 1];
		len_a--;
	}
	stack->index[0] = stack->b[0];
	while (b < stack->len_b)
	{
		stack->b[b] = stack->b[b + 1];
		b++;
	}
	stack->len_b = stack->len_b - 1;
	ft_success("pa\n");
}

int	pb_instruction(t_data *stack)
{
	int i;
	
	i = stack->len_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->index[0];
	stack->len_b++;
	i = 0;
	while (i < stack->len_a - 1)
	{
		stack->index[i] = stack->index[i + 1];
		i++;
	}
	stack->len_a--;
	ft_success("pb\n");
	return (0);
}

void	rrr_instruction(t_data *stack)
{
	rra_instruction(stack, 1);
	rrb_instruction(stack, 1);
	ft_success("rrr\n");
}

void   rr_instruction(t_data *stack)
{
	ra_instruction(stack, 1);
	rb_instruction(stack, 1);
	ft_success("rr\n");
}