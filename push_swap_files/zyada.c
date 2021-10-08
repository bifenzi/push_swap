/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zyada.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:01:49 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/08 11:09:50 by mbifenzi         ###   ########.fr       */
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

int	ft_free(t_data *stack)
{
	free(stack);
	free(stack->a);
	free(stack->b);
	free(stack->index);
	free(stack->sorted);
	stack->a = NULL;
	stack->b = NULL;
	stack->index = NULL;
	stack->sorted = NULL;
	return (1);
}
