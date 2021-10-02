/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:48:59 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/29 17:56:35 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_min(int *t, int *a)
{
	int	i;

	i = 0;
	t[FROMUPA] = 1;
	while (a[i] != t[MINA])
	{
		t[NBRINSA]++;
		i++;
	}
}

void	ft_max(int *t, t_data *a, int *v)
{
	int	i;

	t[FROMUPA] = 1;
	i = 0;
	while (a->index[i] != t[MAXA])
	{
		t[NBRINSA]++;
		i++;
	}
	if (t[NBRINSA] > (t[LENA] / 2))
		*v = -1;
	else
		*v = 1;
}

void	ft_mid(int *t, t_data *a, int b)
{
	int	i;

	i = 0;
	t[NBRINSA] = 1;
	t[FROMUPA] = 1;
	while (i < a->len_a && !(b < a->index[i + 1] && b > a->index[i]))
	{
		t[NBRINSA]++;
		i++;
	}
	if (i == a->len_a)
		t[NBRINSA] = 0;
}

void	number_of_instructions(int *t, int v, int nb)
{
	if (t[NBRINSA] > (t[LENA] / 2))
	{
		t[FROMUPA] = 0;
		t[NBRINSA] = t[LENA] - t[NBRINSA];
	}
	if (nb > (t[LENB] / 2))
	{	
		t[FROMUPB] = 0;
		nb = t[LENB] - nb;
	}
	t[NBRINSA] += v;
	if (t[FROMUPB] == t[FROMUPA])
	{
		if (t[NBRINSA] > nb)
			t[NBRINSAB] = t[NBRINSA];
		else
			t[NBRINSAB] = nb;
	}
	else
		t[NBRINSAB] = t[NBRINSA] + nb;
	if (t[NBAB] > t[NBRINSAB])
		min_instructions(t, nb);
}

void	find_element(int *t, t_data *stack)
{
	int	v;
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (i < stack->len_b)
	{
		t[FROMUPB] = 1;
		v = 0;
		t[NBRINSA] = 0;
		if (stack->b[i] < t[MINA])
			ft_min(t, stack->index);
		else if (stack->b[i] > t[MAXA])
			ft_max(t, stack, &v);
		else
			ft_mid(t, stack, stack->b[i]);
		number_of_instructions(t, v, nb);
		i++;
		nb++;
	}
}
