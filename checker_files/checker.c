/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:00:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/02 18:50:21 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	while (success[i])
	{
		write(1, &success[i], 1);
		i++;
	}
	return (0);
}

int	ft_free(t_data *stack)
{
	free(stack->a);
	free(stack->b);
	stack->a = NULL;
	stack->b = NULL;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*stack;

	stack = malloc(sizeof(t_data));
	stack->len_a = argc - 1;
	stack->a = malloc(sizeof(int) * (stack->len_a));
	stack->b = malloc(sizeof(int) * (stack->len_a));
	stack->len_b = 0;
	if (argc < 2)
		ft_error("\ninvalid arguments\n");
	else if (argc > 2)
		ft_remplir(stack, argc, argv);
	ft_read_instructions(stack);
	ft_check_sort(stack);
	ft_free(stack);
	return (0);
}