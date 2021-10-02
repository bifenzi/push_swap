/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:28:36 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/29 17:56:53 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_upa(int *t, t_data *zb)
{
	while (t[NBA] > 0)
	{
		ra_instruction(zb, 0);
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{	
		rrb_instruction(zb, 0);
		t[NBB]--;
	}
	pa_instruction(zb);
}

void	from_upb(int *t, t_data *zb)
{
	while (t[NBA] > 0)
	{
		rra_instruction(zb, 0);
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{
		rb_instruction(zb, 0);
		t[NBB]--;
	}
	pa_instruction(zb);
}

void	from_upab(int *t, t_data *zb)
{
	while (t[NBA] > 0 && t[NBB] > 0)
	{
		rr_instruction(zb);
		t[NBA]--;
		t[NBB]--;
	}
	while (t[NBA] > 0)
	{
		ra_instruction(zb, 0);
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{
		rb_instruction(zb, 0);
		t[NBB]--;
	}
	pa_instruction(zb);
}

void	from_downab(int *t, t_data *zb)
{
	while (t[NBA] > 0 && t[NBB] > 0)
	{
		rrr_instruction(zb);
		t[NBA]--;
		t[NBB]--;
	}
	while (t[NBA] > 0)
	{
		rra_instruction(zb, 0);
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{
		rrb_instruction(zb, 0);
		t[NBB]--;
	}
	pa_instruction(zb);
}

void	actions(int *t, t_data *h)
{
	if (t[UPA] == 1 && t[UPB] == 0)
		from_upa(t, h);
	else if (t[UPB] == 1 && t[UPA] == 0)
		from_upb(t, h);
	else if (t[UPA] == 1 && t[UPB] == 1)
		from_upab(t, h);
	else if (t[UPA] == 0 && t[UPB] == 0)
		from_downab(t, h);
}
