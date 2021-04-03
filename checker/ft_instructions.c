/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst[i]s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:12:48 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/03 17:46:59 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int     ft_instructions(char **inst, int *stack, int len)
{
    int i;
    int tmp;
    len = 0;
    i = 0;
    printf("|%s|\n", inst[0]);
    while (inst[i])
    {
        //tmp = malloc(sizeof(int));
        if(ft_strcmp(inst[i], "sa") == 0)
        {
            tmp = stack[i];
            stack[i] = stack[i + 1];
            stack[i + 1] = tmp;

        }
        else if(ft_strcmp(inst[i], "sb") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "ss") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "pa") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "pb") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "ra") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "rb") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "rr") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "rra") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "rrb") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "rrr") == 0)
        {
            printf("success");
        }
        else if(ft_strcmp(inst[i], "\n") == 0 || ft_strcmp(inst[i], "\0") == 0 )
        {
            printf("success");
        }
        else
            ft_error("\nINVALID INSTRUCTION \n");
        i++;
    }

    printf("after->|%d\n", stack[0]);
    return(1);
}