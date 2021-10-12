/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:09:57 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/12 18:45:54 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	check_overflow(long r)
{
	if (r > 2147483647 || r < -2147483648)
		return (0);
	return (1);
}

void	ft_read_arguments(t_data *stack, char **argv)
{
	int	j;

	j = 0;
	while (argv[j + 1])
	{
		if(strcmp(argv[j + 1], "-") == 0 || strcmp(argv[j + 1], "+") == 0)
			ft_error("error\n");
		stack->a[j] = ft_atoi(argv[j + 1]);
		j++;
	}
	stack->a[j] = '\0';
}

void	ft_remplir(t_data *stack, char **av)
{
	ft_read_arguments(stack, av);
}
