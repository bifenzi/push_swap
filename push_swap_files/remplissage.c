/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:07:00 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/12 18:44:52 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		stack->sorted[j] = stack->a[j];
		j++;
	}
	stack->a[j] = '\0';
	stack->sorted[j] = stack->a[j];
}

void	ft_remplir(t_data *stack, char **av)
{
	ft_read_arguments(stack, av);
}
