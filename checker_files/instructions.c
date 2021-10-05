/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:11:10 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/05 02:04:59 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotate(t_data *stack)
{
	if (ft_strcmp(stack->inst, "ra") == 0)
	{
		ra_instruction(stack);
		return (1);
	}
	if (ft_strcmp(stack->inst, "rb") == 0)
	{
		rb_instruction(stack);
		return (1);
	}
	if (ft_strcmp(stack->inst, "rr") == 0)
	{
		rr_instruction(stack);
		return (1);
	}
	return (0);
}

int	reverte(t_data *stack)
{
	if (ft_strcmp(stack->inst, "rra") == 0)
	{
		rra_instruction(stack);
		return (1);
	}
	if (ft_strcmp(stack->inst, "rrb") == 0)
	{
		rrb_instruction(stack);
		return (1);
	}
	if (ft_strcmp(stack->inst, "rrr") == 0)
	{
		rrr_instruction(stack);
		return (1);
	}
	return (0);
}

int	swap(t_data *stack)
{
	if (ft_strcmp(stack->inst, "sa") == 0)
	{
		sa_instruction(stack);
		return (1);
	}
	if (ft_strcmp(stack->inst, "sb") == 0)
	{
		sb_instruction(stack);
		return (1);
	}
	if (ft_strcmp(stack->inst, "ss") == 0)
	{
		ss_instruction(stack);
		return (1);
	}
	return (0);
}
