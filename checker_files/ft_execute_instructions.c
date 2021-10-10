/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:52 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/03 19:27:19 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			stack->a[len_a] = stack->a[len_a - 1];
			len_a--;
		}
		stack->a[0] = stack->b[0];
		while (b < stack->len_b)
		{
			stack->b[b] = stack->b[b + 1];
			b++;
		}
		stack->len_b = stack->len_b - 1;
	}	
}

void	pb_instruction(t_data *stack)
{
	int	i;

	if (stack->len_a)
	{
		i = stack->len_b;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		stack->len_b++;
		i = 0;
		while (i < stack->len_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->len_a--;
	}
}

void	ss_instruction(t_data *stack)
{
	sa_instruction(stack);
	sb_instruction(stack);
}

void	rrr_instruction(t_data *stack)
{
	rra_instruction(stack);
	rrb_instruction(stack);
}

void	rr_instruction(t_data *stack)
{
	ra_instruction(stack);
	rb_instruction(stack);
}
