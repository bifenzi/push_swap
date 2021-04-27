/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:22:22 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/27 12:17:29 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra_instruction(t_data stack, int len2)
{
	
	int tmp;
	int i;
	i = 0;
	tmp = *stack.a;
	while(len2 > i)
	{
		stack.a[i] = stack.a[i + 1];
		i++;
	}
	stack.a[*stack.len_a] = tmp;
	ft_success("ra");
}

void	rb_instruction(t_data stack, int len2)
{
	int tmp;
	int i;
	i = 0;
	tmp = stack.b[0];	
	while(len2 > i)
	{
		stack.b[i] = stack.b[i + 1];
		i++;
	}
	stack.b[*stack.len_b] = tmp;
	ft_success("rb");
}

void    rra_instruction(t_data stack, int len2)
{
    int tmp;
    
    tmp = stack.a[*stack.len_a];

		while(len2 >= 0)
		{
			stack.a[len2] = stack.a[len2 - 1];
			len2--;
		}
		stack.a[0] = tmp;
		ft_success("rra\n");
}

void    rrb_instruction(t_data stack, int len2)
{
    int tmp;
    
    tmp = stack.b[*stack.len_b - 1];
	while(len2 > 0)
	{
		stack.b[len2] = stack.b[len2 - 1];
		len2--;
	}
	stack.b[0] = tmp;
	ft_success("rrb");
}