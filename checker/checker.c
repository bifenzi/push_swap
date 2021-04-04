/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:00:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/04 18:37:17 by mbifenzi         ###   ########.fr       */
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
    //exit(0);
    return(-1);
}

int     ft_check_sort(t_data stack, int len)
{
    int before;
    
    len--;
    while(len)
    {
        before = len - 1;
        //printf("check sort->|%d|\n", stack.a[len]);
        if(stack.a[len] > stack.a[before])
            len--;
        if(stack.a[len] < stack.a[before])
            return(ft_error("KO"));
    }
    //printf("check sort->|%d|\n", stack.a[len]);
    return(ft_success("OK"));
}

int main(int argc, char **argv)
{
    int len;
    int j;
    t_data stack;
    int i;
    char *instruction;
    //char **inst;
    stack.inst = NULL;
    i = 0;
    len = 0;
    j = 1;
    stack.a = malloc(sizeof(int) * ft_strlen(argv[j]));
    stack.b = malloc(sizeof(int) * ft_strlen(argv[j]));
    if(argc < 2)
        ft_error("\ninvalid arguments\n");
    else
    {
        while (argv[j])
        {
            stack.a[len] = ft_atoi(argv[j]);
            len++;
            j++;
        }
    }
    len--;
    instruction = (char*)malloc(len * sizeof(char*));
    stack.inst = (char**)malloc(len * sizeof(char*));
    while (get_next_line(0, &instruction) > 0)
    {
            stack.inst[i] = ft_strdup(instruction);
            i++;
    }
    stack.inst[i + 1] = "\0";
    //printf("|%s|\n", inst[0]);
    i = 0;
    ft_instructions(stack, len);
    ft_check_sort(stack, len);
    return(0);
}