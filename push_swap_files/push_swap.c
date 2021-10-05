/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/05 16:27:04 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_data *stack)
{
	int	i;
	int	k;
	int	z;

	z = 0;
	i = 0;
	k = 0;
	while (!ft_check_sort(stack))
	{
		if (stack->index[i] >= k && stack->index[i] < k + 12)
		{
			k = stack->index[i];
			ra_instruction(stack, z);
		}
		else
			pb_instruction(stack);
	}
}

void	final_touch(t_data *stack)
{
	int	i;

	i = 0;
	if (!ft_check_sort(stack))
	{
		while (i < stack->len_a)
		{
			if (stack->index[i] == 0)
				break ;
			i++;
		}
		if (i > stack->len_a / 2)
		{
			i = stack->len_a - i;
			while (i)
			{
				rra_instruction(stack, 0);
				i--;
			}
		}
		else
			while (i--)
				ra_instruction(stack, 0);
	}
}

void	fillindex(t_data *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= stack->len_a)
	{
		j = 0;
		while (stack->a[i] != stack->sorted[j])
			j++;
		stack->index[i] = j;
		i++;
	}
}

void	ft_sort_table(t_data *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < stack->len_a)
		stack->sorted[i] = stack->a[i];
	i = 0;
	while (i < stack->len_a)
	{
		j = i + 1;
		while (j < stack->len_a)
		{
			if (stack->sorted[i] > stack->sorted[j])
			{
				tmp = stack->sorted[i];
				stack->sorted[i] = stack->sorted[j];
				stack->sorted[j] = tmp;
			}
			if (stack->sorted[j] == stack->sorted[i])
				ft_error("INVALID ARGUMENTS\n");
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*stack;

	stack = malloc(sizeof(t_data));
	stack->len_a = argc - 1;
	stack->len_b = 0;
	stack->max_len = argc - 1;
	stack->a = malloc(sizeof(int) * (stack->len_a));
	stack->b = malloc(sizeof(int) * (stack->len_a));
	stack->sorted = malloc(sizeof(int) * (stack->len_a));
	stack->index = malloc(sizeof(int) * (stack->len_a));
	ft_remplir(stack, argv);
	ft_sort_table(stack);
	fillindex(stack);
	if (argc == 4)
		ft_sort3(stack);
	else if (argc == 6 && stack->index[1] == 4)
		ft_sort5(stack);
	else
	{
		push_to_b(stack);
		push_to_a(stack);
		final_touch(stack);
	}
}
