/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:52 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/02 18:30:22 by mbifenzi         ###   ########.fr       */
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
	if(ft_strcmp(stack->inst, "sa") == 0 || ft_strcmp(stack->inst, "ss") == 0)
		sa_instruction(stack);
	if(ft_strcmp(stack->inst, "sb") == 0 || ft_strcmp(stack->inst, "ss") == 0)
		sb_instruction(stack);
}

void	rrr_instruction(t_data *stack)
{
	if(ft_strcmp(stack->inst, "rra") == 0 || ft_strcmp(stack->inst, "rrr") == 0)
		rra_instruction(stack);
	if(ft_strcmp(stack->inst, "rrb") == 0 || ft_strcmp(stack->inst, "rrr") == 0)
		rrb_instruction(stack);
}

void	rr_instruction(t_data *stack)
{
	if(ft_strcmp(stack->inst, "ra") == 0 || ft_strcmp(stack->inst, "rr") == 0)
		ra_instruction(stack);
	if(ft_strcmp(stack->inst, "rb") == 0 || ft_strcmp(stack->inst, "rr") == 0)
		rb_instruction(stack);
}
