/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:15:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/03 17:41:58 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_check_pos(int c, int *sorted)
{
	int	i;

	i = 0;
	while (sorted[i])
	{
		if (c == sorted[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_check_sort(t_data *stack)
{
	int	after;
	int	len;

	len = 0;
	while (len < stack->len_a - 1)
	{
		after = len + 1;
		if (stack->index[len] > stack->index[after])
			return (0);
		len++;
	}
	return (1);
}
