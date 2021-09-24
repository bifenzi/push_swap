/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:52 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/24 17:23:57 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_instruction(t_data *stack)
{
	int	b;
	int	len_a;

	b = 0;
	if (stack->len_b)
	{
		stack->len_a = stack->len_a + 1;
		len_a = stack->len_a;
		while (len_a > 0)
		{
			stack->index[len_a] = stack->index[len_a - 1];
			len_a--;
		}
		stack->index[0] = stack->b[0];
		stack->len_b = stack->len_b - 1;
		while (b <= stack->len_b - 1)
		{
			stack->b[b] = stack->b[b + 1];
			b++;
		}
	}
	stack->b[b + 1] = 0;
	ft_success("pa\n");
}

int	pb_instruction(t_data *stack)
{
	int	a;
	a = 0;
	int len2;
	len2=0;
	if (stack->len_a)
	{
		len2 = stack->len_b - 1;
		while (len2 >= 0)
		{
			stack->b[len2] = stack->b[len2 - 1];
			len2--;
		}
		stack->b[0] = stack->index[0];
		while (a < stack->len_a)
		{
			stack->index[a] = stack->index[a + 1];
			a++;
		}
		stack->len_a = stack->len_a - 1;
		stack->len_b = stack->len_b + 1;
	}
	ft_success("pb\n");
	return len2;
}


void	ss_instruction(t_data *stack)
{
	int l = 1;
	sa_instruction(stack,l);
	sb_instruction(stack,l);
	ft_success("ss\n");
}

void	rrr_instruction(t_data *stack)
{
	int k = 1;
	rra_instruction(stack, k);
	rrb_instruction(stack, k);
	ft_success("rrr\n");
}

void   rr_instruction(t_data *stack)
{
	int j = 1;
		ra_instruction(stack, j);
		rb_instruction(stack, j);
		ft_success("rr\n");
}