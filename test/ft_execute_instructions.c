/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:52 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/24 13:37:59 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		while (b < *stack.len_b)
		{
			stack.b[b] = stack.b[b + 1];
			b++;
		}
	}
	ft_success("pa\n");
}

void	pb_instruction(t_data stack, int len2)
{
	int	a;

	a = 0;
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
}

void	ss_instruction(t_data stack)
{
	//if(ft_strcmp(stack.inst, "sa") == 0 || ft_strcmp(stack.inst, "ss") == 0)
		sa_instruction(stack);
	//if(ft_strcmp(stack.inst, "sb") == 0 || ft_strcmp(stack.inst, "ss") == 0)
		sb_instruction(stack);
	//ft_success("ss\n");
}

void	rrr_instruction(t_data stack, int len2)
{
	len2 = *stack.len_a;
	if(ft_strcmp(stack.inst, "rra") == 0 || ft_strcmp(stack.inst, "rrr") == 0)
		rra_instruction(stack, len2);
	len2 = *stack.len_b;
	if(ft_strcmp(stack.inst, "rrb") == 0 || ft_strcmp(stack.inst, "rrr") == 0)
		rrb_instruction(stack, len2);
}

void   rr_instruction(t_data stack, int len2)
{
	if(ft_strcmp(stack.inst, "ra") == 0 || ft_strcmp(stack.inst, "rr") == 0)
		ra_instruction(stack, len2);
	if(ft_strcmp(stack.inst, "rb") == 0 || ft_strcmp(stack.inst, "rr") == 0)
		rb_instruction(stack, len2);
}