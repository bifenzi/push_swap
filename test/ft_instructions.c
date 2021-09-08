/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.insts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:12:48 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/04/13 18:00:27 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void    sa_instruction(t_data stack, int l)
{
    int tmp;
    
    tmp = stack.a[0];
		stack.a[0] = stack.a[1];
		stack.a[1] = tmp;
	if(l == 0)
		ft_success("sa\n");
}

void    sb_instruction(t_data stack, int l)
{
    int tmp;
    
    tmp = stack.b[0];
		stack.b[0] = stack.b[1];
		stack.b[1] = tmp;
	if(l == 0)
		ft_success("sb\n");
}

int	ft_read_instructions(t_data stack)
{
	while (get_next_line(0, &stack.inst) > 0)
	{
		ft_instructions(stack);
		free(stack.inst);
		stack.inst = NULL;
	}
	free(stack.inst);
	stack.inst = NULL;
	return (1);
}

/*int	ft_instructions(t_data stack)
{
	int	i;
	int	len2;

	len2 = *stack.len_a;
	i = 0;
	if (ft_strcmp(stack.inst, "sa") == 0 || ft_strcmp(stack.inst, "sb") == 0
		||ft_strcmp(stack.inst, "ss") == 0)
		ss_instruction(stack);
	else if (ft_strcmp(stack.inst, "pa") == 0)
		pa_instruction(stack);
	else if (ft_strcmp(stack.inst, "pb") == 0)
		pb_instruction(stack, len2);
	else if (ft_strcmp(stack.inst, "ra") == 0
		|| ft_strcmp(stack.inst, "rb") == 0 || ft_strcmp(stack.inst, "rr") == 0)
		rr_instruction(stack, len2);
	else if (ft_strcmp(stack.inst, "rra") == 0
		|| ft_strcmp(stack.inst, "rrb") == 0
		|| ft_strcmp(stack.inst, "rrr") == 0)
		rrr_instruction(stack, len2);
	else if (ft_strcmp(stack.inst, "\n") == 0 || ft_strcmp(stack.inst, "\0") == 0)
		printf("success");
	else
		ft_error("\nINVALID INSTRUCTION \n");
	i++;
	return (1);
}
*/
