/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:22:22 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/02 16:51:35 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
void	ra_instruction(t_data *stack)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->len_a)
	{
		tmp = stack->a[i];
		while (i < stack->len_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[stack->len_a - 1] = tmp;
	}
}

void	rb_instruction(t_data *stack)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->len_b)
	{
		tmp = stack->b[i];
		while (i < stack->len_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[stack->len_b - 1] = tmp;
	}
}

void	rra_instruction(t_data *stack)
{
	int	tmp;
	int	len2;

	if (stack->len_a)
	{
		len2 = stack->len_a;
		tmp = stack->a[stack->len_a - 1];
		while (len2 > 0)
		{
			stack->a[len2] = stack->a[len2 - 1];
			len2--;
		}
		stack->a[0] = tmp;
	}
}

void	rrb_instruction(t_data *stack)
{
	int	tmp;
	int	len2;

	len2 = stack->len_b;
	if (stack->len_b)
	{
		tmp = stack->b[stack->len_b - 1];
		while (len2 > 0)
		{
			stack->b[len2] = stack->b[len2 - 1];
			len2--;
		}
		stack->b[0] = tmp;
	}
}
