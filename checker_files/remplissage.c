/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:09:57 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/02 19:41:44 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_overflow(char *str)
{
	long long	r;

	r = ft_overflowhelper(str);
	if (ft_strlen(str) > 15)
		return (1);
	if (r > 2147483647 || r < -2147483648)
		return (1);
	return (0);
}

int	ft_check_number(char *str)
{
	if (*(str + 1) != '\0' && (*str == '+' || *str == '-'))
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	ft_check_duplicate(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_check_number(av[i]) || check_overflow(av[i]))
			return (1);
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[j], "+0") == 0 || ft_strcmp(av[j], "-0") == 0)
				av[j] = "0";
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_read_arguments(t_data *stack, char **argv)
{
	int	j;

	j = 0;
	while (argv[j + 1])
	{
		stack->a[j] = ft_atoi(argv[j + 1]);
		j++;
	}
	stack->a[j] = '\0';
}

void	ft_remplir(t_data *stack, int ac, char **av)
{
	if (ft_check_duplicate(ac, av))
		ft_error("error\n");
	else
		ft_read_arguments(stack, av);
}
