/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:16:07 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/08 10:51:30 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_data *stack)
{
	while (!ft_check_sort(stack))
	{
		if (stack->index[0] > stack->index[1]
			&& stack->index[0] > stack->index[2])
			ra_instruction(stack, 0);
		else if (stack->index[2] < stack->index[0])
			rra_instruction(stack, 0);
		else if (stack->index[0] > stack->index[1])
			sa_instruction(stack, 0);
		else if (stack->index[1] > stack->index[2])
		{
			rra_instruction(stack, 0);
			sa_instruction(stack, 0);
		}
	}
}

int	ft_sort6(t_data *stack)
{
	if (stack->index[0] == 0 && stack->index[1] == 4 && stack->index[2] == 3
		&& stack->index[3] == 2 && stack->index[4] == 1)
	{
		pb_instruction(stack);
		rra_instruction(stack, 0);
		pb_instruction(stack);
		sa_instruction(stack, 0);
		rra_instruction(stack, 0);
		pa_instruction(stack);
		pa_instruction(stack);
		return (1);
	}
	return (0);
}

int	ft_sort5(t_data *stack)
{
	if (stack->index[0] == 0 && stack->index[1] == 4 && stack->index[2] == 3
		&& stack->index[3] == 1 && stack->index[4] == 2)
	{
		pb_instruction(stack);
		rra_instruction(stack, 0);
		rra_instruction(stack, 0);
		pb_instruction(stack);
		sa_instruction(stack, 0);
		ra_instruction(stack, 0);
		pa_instruction(stack);
		pa_instruction(stack);
		return (1);
	}
	return (0);
}
