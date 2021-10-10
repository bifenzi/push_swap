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

int	sghir(t_data *stack, int *number)
{
	int	i;
	int	j;
	int	min;
	int	value;

	i = 0;
	min = 0;
	j = i + 1;
	value = number[i];
	while (i < stack->len_a)
	{
		j = i + 1;
		while (j < stack->len_a)
		{
			if (value > number[j])
			{
				value = number[j];
				min = j;
			}
			j++;
		}
		i++;
	}
	// printf("%d\n\n", min);
	return (min);
}

void	pushit(t_data *stack, int min, int fromup)
{
	if (fromup == 1)
	{
		while (min)
		{			
			rra_instruction(stack, 0);
		}		
		pb_instruction(stack);
	}
	if (fromup == 0)
	{
		while (min)
			ra_instruction(stack, 0);
		pb_instruction(stack);
	}
}

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

void	ft_sort4(t_data *stack)
{
	int	min;

	min = sghir(stack, stack->index);
	if (min == 1)
		ra_instruction(stack, 0);
	else if (min == 2)
	{
		rra_instruction(stack, 0);
		rra_instruction(stack, 0);
	}
	else if (min == 3)
		rra_instruction(stack, 0);
	pb_instruction(stack);
	ft_sort3(stack);
	pa_instruction(stack);
}

void	ft_sort5(t_data *stack)
{
	int	min;

	min = sghir(stack, stack->index);
	if (min == 1)
		ra_instruction(stack, 0);
	else if (min == 2)
	{
		ra_instruction(stack, 0);
		ra_instruction(stack, 0);
	}
	else if (min == 3)
	{
		rra_instruction(stack, 0);
		rra_instruction(stack, 0);
	}
	else if (min == 4)
		rra_instruction(stack, 0);
	pb_instruction(stack);
	ft_sort4(stack);
	pa_instruction(stack);
}
