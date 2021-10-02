/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:15:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/29 20:48:29 by mbifenzi         ###   ########.fr       */
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

long long	ft_overflowhelper(char *str)
{
	long long	a;
	long		sign;

	a = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		str++;
		sign = (-1);
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	if (a < 0 && sign < 0)
		return (0);
	if (a < 0 && sign > 0)
		return (-1);
	return (a * sign);
}

int	ft_check_sort(t_data *stack)
{
	int	before;
	int	len;

	len = 0;
	while (len < stack->len_a - 1)
	{
		before = len + 1;
		if (stack->index[len] > stack->index[before])
			return (0);
		len++;
	}
	return (1);
}
