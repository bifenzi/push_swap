/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zyada.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:01:49 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/12 15:23:10 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int     ft_success(char *success)
{
    int i;
    i = 0;
    while (success[i])
    {
        write(1, &success[i], 1);
        i++;
    }
    return(0);
}
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


int ft_free(t_data stack, int *sorted)
{
    free(stack.a);
    free(stack.b);
    free(stack.len_a);
    free(stack.len_b);
    free(sorted);

    stack.a = NULL;
    stack.b = NULL;
    stack.len_a = NULL;
    stack.len_a = NULL;
    return(1);
}

int         *ft_read_arguments(t_data stack, int *a, char **argv)
{
    int j;

    j = 0;
    while (argv[j + 1])
    {
        stack.a[j] = ft_atoi(argv[j + 1]);
        a[j] = stack.a[j];
        j++;
    }
    stack.a[j] = '\0';
    a[j] = stack.a[j];
    return(a);
}