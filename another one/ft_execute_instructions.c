/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:52 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/06/28 17:36:27 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_instruction(t_data stack,t_sort the)
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
	ft_9elleb(stack,the);
	ft_success("pa\n");
}

int	pb_instruction(t_data stack, t_sort the)
{
	int	a;
	a = 0;
	int len2;
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
	ft_9elleb(stack,the);
	return len2;
}


void	ss_instruction(t_data stack, t_sort the)
{
	int l = 1;
	sa_instruction(stack,l,the);
	sb_instruction(stack,l,the);
	ft_9elleb(stack,the);
	ft_success("ss\n");
}

void	rrr_instruction(t_data stack, t_sort the)
{
	int k = 1;
	rra_instruction(stack, k,the);
	rrb_instruction(stack, k, the);
	ft_success("rrr\n");
	ft_9elleb(stack,the);
}

void   rr_instruction(t_data stack,t_sort the)
{
	int j = 1;
		ra_instruction(stack, j,the);
		rb_instruction(stack, j,the);
		ft_9elleb(stack,the);
		ft_success("rr\n");
}