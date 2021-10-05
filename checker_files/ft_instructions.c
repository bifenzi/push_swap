/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:12:48 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/03 19:54:25 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_instruction(t_data *stack)
{
	int	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
}

void	sb_instruction(t_data *stack)
{
	int	tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
}

int	ft_read_instructions(t_data *stack)
{
	while (get_next_line(0, &stack->inst) > 0)
	{
		ft_instructions(stack);
		free(stack->inst);
		stack->inst = NULL;
	}
	free(stack->inst);
	stack->inst = NULL;
	return (1);
}

int	ft_instructions(t_data *stack)
{
	int	i;

	i = 0;
	if (swap(stack) + rotate(stack) + reverte(stack) == 0)
		ft_error("INVALID INSTRUCTION \n");
	i++;
	return (1);
}
