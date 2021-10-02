/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:08:04 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/01 23:19:56 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int     ft_error(char *error)
{
    int i;
    i = 0;

    while (error[i])
    {
        write(1, &error[i], 1);
        i++;
    }
    exit(0);
    return(1);
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

	len = stack->len_a - 1;
	if (len == 0)
        return(ft_error("KO")); 
    while (len)
    {
        before = len - 1;
        if (stack->a[len] > stack->a[before])
            len--;
        if(stack->a[len] < stack->a[before])
            return(ft_error("KO"));
    }
    if (len == 0)
        return(ft_success("OK"));
    return(0);
}