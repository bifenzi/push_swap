/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:16:07 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/05 17:00:04 by mbifenzi         ###   ########.fr       */
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

void	ft_sort5(t_data *stack)
{
	pb_instruction(stack);
	rra_instruction(stack, 0);
	rra_instruction(stack, 0);
	pb_instruction(stack);
	sa_instruction(stack, 0);
	ra_instruction(stack, 0);
	pa_instruction(stack);
	pa_instruction(stack);
}
