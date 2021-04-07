/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.insts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:12:48 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/06 17:30:41 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int      ss_instruction(t_data stack)
{
    int tmp;

    if(ft_strcmp(stack.inst, "sa") == 0 || ft_strcmp(stack.inst, "ss") == 0)
    {
        tmp = stack.a[0];
        stack.a[0] = stack.a[1];
        stack.a[1] = tmp;
        //ft_success("nice");
    }
    if(ft_strcmp(stack.inst, "sb") == 0 || ft_strcmp(stack.inst, "ss") == 0)
    {
        tmp = stack.b[0];
        stack.b[0] = stack.b[1];
        stack.b[1] = tmp;
    }
    return(1);
}
int      rr_instruction(t_data stack, int len2, int len)
{
    int *tmp;
    tmp = malloc(sizeof(int) * len);

    if(ft_strcmp(stack.inst, "ra") == 0 || ft_strcmp(stack.inst, "rr") == 0)
    {
        int i;
        i = 0;
        //printf("before|%d|\n", stack.a[0]);
        tmp[0] = stack.a[0];
        while(len2 >= i)
        {
            stack.a[i] = stack.a[i + 1];
            i++;
        }
        stack.a[len] = tmp[0];
        //printf("after|%d|\n", stack.a[0]);
    }
    if(ft_strcmp(stack.inst, "rb") == 0 || ft_strcmp(stack.inst, "rr") == 0)
    {
        int i;
        i = 0;
        //printf("before|%d|\n", stack.a[0]);
        tmp[0] = stack.b[0];
        while(len2 >= i)
        {
            stack.b[i] = stack.b[i + 1];
            i++;
        }
        stack.b[len] = tmp[0];
        //printf("after|%d|\n", stack.a[0]);
    }
    return(1);
}
int     ft_instructions(t_data stack, int len)
{
    int i;
    int *tmp;
    int len2;
    len2 = len;
    i = 0;
    tmp = malloc(sizeof(int) * len);
    if(ft_strcmp(stack.inst, "sa") == 0 || ft_strcmp(stack.inst, "sb") == 0 ||
        ft_strcmp(stack.inst, "ss") == 0)
        ss_instruction(stack);
    else if(ft_strcmp(stack.inst, "pa") == 0)
    {
        tmp[0] = stack.a[0];
        stack.a[0] = stack.b[0];
        stack.b[0] = tmp[0];
        free(tmp);
    }
        else if(ft_strcmp(stack.inst, "pb") == 0)
        {
            tmp[0] = stack.b[0];
            stack.b[0] = stack.a[0];
            stack.a[0] = tmp[0];
            free(tmp);
        }
    else if(ft_strcmp(stack.inst, "ra") == 0 || ft_strcmp(stack.inst, "rb") == 0
            || ft_strcmp(stack.inst, "rr") == 0)
        rr_instruction(stack, len2, len);

    else if(ft_strcmp(stack.inst, "rra") == 0)
    {
        printf("success");
    }
    else if(ft_strcmp(stack.inst, "rrb") == 0)
    {
        printf("success");
    }
    else if(ft_strcmp(stack.inst, "rrr") == 0)
    {
        printf("success");
    }
    else if(ft_strcmp(stack.inst, "\n") == 0 || ft_strcmp(stack.inst, "\0") == 0 )
    {
        printf("success");
    }
    else
        ft_error("\nINVALID INSTRUCTION \n");
    i++;
    //printf("after->|%d\n", stack_a[0]);
    return(1);
}