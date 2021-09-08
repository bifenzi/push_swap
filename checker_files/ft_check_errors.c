/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:08:04 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/07/01 17:53:24 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
int INT32_MIN = 2147483647;
int INT32_MAX = -2147483647;
void    ft_check_numbers(char **argv)
{
    int i;
    int j;
    long a;

    i = 1;
    while (argv[i])
    {
        j = 0;
        if (argv[i][0] == '-')
            j++;
        while (argv[i][j])
        {
            if(!ft_isdigit((argv[i][j])))
                ft_error("NOT INTEGER");
            j++;
        }
        a = ft_atoi(argv[i]);
        a = ft_atoi(argv[i]);
        if (a > 2147483647 || a < -2147483647)
        {
            ft_error("NOT INTEGER\n");
        }
        i++;
    }
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

int     ft_check_sort(t_data stack)
{
    int before;
    int len;

    len = *stack.len_a;
    if (len == 0)
        return(ft_error("KO")); 
    while(len)
    {
        before = len - 1;
        if(stack.a[len] > stack.a[before])
            len--;
        if(stack.a[len] < stack.a[before])
            return(ft_error("KO"));
    }
    if (len == 0)
        return(ft_success("OK"));
    return(0);
}