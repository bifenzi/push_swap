/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:52 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/11 17:11:05 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_instruction(t_data stack)
{
	int	b;
	int	len_a;

	b = 0;
	if (*stack.len_b)
	{
		*stack.len_a = *stack.len_a + 1;
		len_a = *stack.len_a;
		while (len_a > 0)
		{
			stack.a[len_a] = stack.a[len_a - 1];
			len_a--;
		}
		stack.a[0] = stack.b[0];
		*stack.len_b = *stack.len_b - 1;
		while (b <= *stack.len_b)
		{
			stack.b[b] = stack.b[b + 1];
			b++;
		}
	}
	stack.b[b + 1] = 0;
	ft_success("pa\n");
}

int	pb_instruction(t_data stack)
{
	int	a;
	a = 0;
	int len2;
	len2=0;
	if (*stack.len_a)
	{
		len2 = *stack.len_b;
		while (len2 > 0)
		{
			stack.b[len2] = stack.b[len2 - 1];
			len2--;
		}
		stack.b[0] = stack.a[0];
		while (a < *stack.len_a)
		{
			stack.a[a] = stack.a[a + 1];
			a++;
		}
		*stack.len_a = *stack.len_a - 1;
		*stack.len_b = *stack.len_b + 1;
	}
	ft_success("pb\n");
	return len2;
}


void	ss_instruction(t_data stack)
{
	int l = 1;
	sa_instruction(stack,l);
	sb_instruction(stack,l);
	ft_success("ss\n");
}

void	rrr_instruction(t_data stack)
{
	int k = 1;
	rra_instruction(stack, k);
	rrb_instruction(stack, k);
	ft_success("rrr\n");
}

void   rr_instruction(t_data stack)
{
	int j = 1;
		ra_instruction(stack, j);
		rb_instruction(stack, j);
		ft_success("rr\n");
}