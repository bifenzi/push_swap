/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.insts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:12:48 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/13 18:00:27 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void    sa_instruction(t_data *stack, int l)
{
    int tmp;

    tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	if(l == 0)
		ft_success("sa\n");
}

void    sb_instruction(t_data *stack, int l)
{
    int tmp;

    tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	if(l == 0)
		ft_success("sb\n");
}