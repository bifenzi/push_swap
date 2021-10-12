/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zyada.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:01:49 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/11 22:11:23 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_success(char *success)
{
	int	i;

	i = 0;
	while (success && success[i])
	{
		write(1, &success[i], 1);
		i++;
	}
	return (0);
}

int	ft_error(char *error)
{
	int	i;

	i = 0;
	while (error[i])
	{
		write(1, &error[i], 1);
		i++;
	}
	exit(0);
	return (1);
}

void	everything(t_data *stack, int argc)
{
	if (ft_check_sort(stack))
		exit (0);
	if (argc == 4)
		ft_sort3(stack);
	if (argc == 5)
		ft_sort4(stack);
	else if (argc == 6)
		ft_sort5(stack);
	else
	{
		push_to_b(stack);
		push_to_a(stack);
		final_touch(stack);
	}
}
