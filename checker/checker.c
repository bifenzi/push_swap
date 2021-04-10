/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:00:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/10 19:21:36 by mbifenzi         ###   ########.fr       */
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

void    ft_check_duplicate(t_data stack)
{
    int i;
    int j ;

    j = 0;
    i = 0;
    while (stack.a[i])
    {
        j = 0;
        while (stack.a[j])
        {
            if (stack.a[i] == stack.a[j] && j != i)
                ft_error("error");
            j++;
        }
        i++;
    }
}
int     ft_check_sort(t_data stack, int len)
{
    int before;
    
    len--;
    while(len)
    {
        //printf("\nstaaack a %d\n",stack.a[len]);
        before = len - 1;
        if(stack.a[len] > stack.a[before])
            len--;
        if(stack.a[len] < stack.a[before])
            return(ft_error("KO"));
    }
    if (len == 0)
        ft_success("OK");
    return(0);
}
void    ft_check_numbers(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if(!ft_isdigit((argv[i][j])))
                ft_error("NOT INTEGER");
                j++;
        }
        i++;
    }
}
int ft_free(t_data stack)
{
    free(stack.a);
    free(stack.b);
    stack.a = NULL;
    stack.b = NULL;
    return(1);
}
int main(int argc, char **argv)
{
    int j;
    t_data stack;
    stack.len_a = argc - 1;
    stack.pb = 0;
    stack.pa = 0;
    j = 0;
    stack.len_b = malloc(10);
    stack.len_b[0] = 0;
    printf("\nstack a - - - > %d\n",stack.len_b[0]);
    stack.a = malloc(sizeof(int) * (argc));
    stack.b = malloc(sizeof(int) *  (argc));
    if(argc < 2)
        ft_error("\ninvalid arguments\n");
    else if (argc > 2)
    {
        while (argv[j + 1])
        {
            stack.a[j] = ft_atoi(argv[j + 1]);
            j++;
        }
    }
    stack.a[j] = '\0';
    ft_check_numbers(argv);
    ft_check_duplicate(stack);
    ft_read_arguments(stack, argc);
    // printf("\nstack pb - - - > %d\n",stack.len_b);
    ft_check_sort(stack, argc - 1);
    ft_free(stack);
    return(0);
}