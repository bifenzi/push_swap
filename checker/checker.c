/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:00:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/02 17:42:53 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
    return(-1);
}

int     ft_check_sort(int *stack, int len)
{
    int before;
    
    len--;
    while(len)
    {
        before = len - 1;
        printf("%d\n", stack[len]);
        if(stack[len] > stack[before])
            len--;
        if(stack[len] < stack[before])
            return(ft_error("KO"));
    }
    printf("%d\n", stack[len]);
    return(ft_success("OK"));
}

int main(int argc, char **argv)
{
    int len;
    int j;
    int *stack;
        
    len = 0;
    j = 1;
    stack = malloc(sizeof(int) * ft_strlen(argv[j]));
    if(argc < 2)
        ft_error("invalid arguments");
    else
    {
        while (argv[j])
        {
            stack[len] = ft_atoi(argv[j]);
            len++;
            j++;
        }
    }
    ft_check_sort(stack, len);
    printf("%d\n", len);
    //ft_instructions(stack);
    return(0);
}