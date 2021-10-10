/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:47:16 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/29 21:18:03 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_instructions(int *t, int nb)
{
	t[UPA] = t[FROMUPA];
	t[UPB] = t[FROMUPB];
	t[NBA] = t[NBRINSA];
	t[NBB] = nb;
	t[NBAB] = t[NBRINSAB];
}

void	initialiser(int *t)
{
	t[MINA] = MAXIM;
	t[MAXA] = 0;
	t[NBRINSA] = 0;
	t[NBRINSB] = 0;
	t[NBRINSAB] = 0;
	t[LENA] = 0;
	t[LENB] = 0;
	t[NBA] = 0;
	t[NBB] = 0;
	t[NBAB] = MAXIM;
	t[FROMUPA] = 1;
	t[FROMUPB] = 1;
	t[UPA] = 0;
	t[UPB] = 0;
}

void	size(t_data *stack, int *t)
{
	int	i;

	i = 0;
	t[MINA] = stack->index[0];
	t[MAXA] = stack->index[0];
	t[LENA] = 0;
	t[LENB] = 0;
	while (i < stack->len_a)
	{
		if (stack->index[i] < t[MINA])
			t[MINA] = stack->index[i];
		else if (stack->index[i] > t[MAXA])
			t[MAXA] = stack->index[i];
		i++;
	}
	t[LENA] = stack->len_a;
	t[LENB] = stack->len_b;
}

void	push_to_a(t_data *stack)
{
	int		t[14];

	while (stack->len_b > 0)
	{
		initialiser(t);
		size(stack, t);
		find_element(t, stack);
		actions(t, stack);
	}
}
