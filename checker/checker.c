/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:00:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/03 18:12:59 by mbifenzi         ###   ########.fr       */
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

int     ft_check_sort(int *stack, int len)
{
    int before;
    
    len--;
    while(len)
    {
        before = len - 1;
        printf("check-->|%d||\n", stack[len]);
        if(stack[len] > stack[before])
            len--;
        if(stack[len] < stack[before])
            return(ft_error("KO"));
    }
    printf("||%d||\n", stack[len]);
    return(ft_success("OK"));
}

int main(int argc, char **argv)
{
    int len;
    int j;
    int *stack;
    int i;
    char *instruction;
    char **inst;
    inst = NULL;
    i = 0;
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
    instruction = (char*)malloc(len * sizeof(char*));
    inst = (char**)malloc(len * sizeof(char*));
    while (get_next_line(0, &instruction) > 0)
    {
            inst[i] = ft_strdup(instruction);
            i++;
    }
    inst[i + 1] = "\0";
    //printf("|%s|\n", inst[0]);
    i = 0;
    ft_check_sort(stack, len);
    ft_instructions(inst, stack, len);
    return(0);
}