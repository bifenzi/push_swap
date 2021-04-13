/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:00:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/13 15:23:12 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
    return(1);
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
    return(-1);
}


int ft_free(t_data stack)
{
    free(stack.a);
    free(stack.b);
    free(stack.len_a);
    free(stack.len_b);
    stack.a = NULL;
    stack.b = NULL;
    stack.len_a = NULL;
    stack.len_a = NULL;
    return(1);
}

int         ft_read_arguments(t_data stack, char **argv)
{
    int j;

    j = 0;
    while (argv[j + 1])
    {
        stack.a[j] = ft_atoi(argv[j + 1]);
        j++;
    }
    stack.a[j] = '\0';
    return(0);
}
int main(int argc, char **argv)
{
    t_data stack;
    
    stack.len_a = malloc(sizeof(int));
    stack.len_b = malloc(sizeof(int));
    stack.a = malloc(sizeof(int) * (argc));
    stack.b = malloc(sizeof(int) *  (argc));   
    *stack.len_a = argc - 2;
    *stack.len_b = 0;
    if(argc < 2)
        ft_error("\ninvalid arguments\n");
    else if (argc > 2)
        ft_read_arguments(stack, argv);
    
    ft_check_numbers(argv);
    ft_check_duplicate(stack);
    ft_read_instructions(stack);
    ft_check_sort(stack, *stack.len_a);
    ft_free(stack);
    while(1);
    return(0);
}