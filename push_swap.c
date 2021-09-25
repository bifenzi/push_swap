/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:44 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/25 18:31:38 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int     ft_check_pos(int c, int *sorted)
{
    int i = 0;
   
    while (sorted[i])
    {
        if (c  == sorted[i])
            return (i);
        i++;
    }
    return(0);
}

void    ft_sort_table(t_data *stack)
{
    int i;
    int j;
    int tmp;
    i = 0;
    while (i <= stack->len_a)
    {
        stack->sorted[i] = stack->a[i];
        i++;
    }
    i = 0;
    while (i <= stack->len_a)
    {
        j = i + 1;
        while (j <= stack->len_a)
        {
            if (stack->sorted[i] > stack->sorted[j])
            {
                tmp = stack->sorted[i];
                stack->sorted[i] = stack->sorted[j];
                stack->sorted[j] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 0;
}

int     ft_check_number(char *str)
{
    if (*(str + 1) != '\0' && (*str == '+' || *str == '-'))
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

long long	ft_overflowhelper(char *str)
{
	long long	a;
	long		sign;

	a = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		str++;
		sign = (-1);
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	if (a < 0 && sign < 0)
		return (0);
	if (a < 0 && sign > 0)
		return (-1);
	return (a * sign);
}

int	check_overflow(char *str)
{
	long long	r;

	r = ft_overflowhelper(str);
	if (ft_strlen(str) > 15)
		return (1);
	if (r > 2147483647 || r < -2147483648)
		return (1);
	return (0);
}

int     ft_check_duplicate(int ac, char **av)
{
    int i; 
    int j;

    i = 1;
    j = 0;
    while (i < ac)
    {
        if (ft_check_number(av[i]) || check_overflow(av[i]))
            return (1);
        j = i + 1;
        while (j < ac)
        {
            if (ft_strcmp(av[i], av[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
void    ft_remplir(t_data *stack, int ac, char **av)
{
    if (ft_check_duplicate(ac, av))
        ft_error("error\n");
    else
        ft_read_arguments(stack ,av);
}

void    fillindex(t_data *stack)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i <= stack->len_a)
    {
        j = 0;
        while (stack->a[i] != stack->sorted[j])
            j++;
        stack->index[i] = j;
        i++;
    }
}
int     ft_check_sort(t_data *stack)
{
    int before;
    int len;

    len = 0;
    while(len < stack->len_a)
    {   
        before = len + 1;
        if(stack->index[len] > stack->index[before])
            return(0);
        len++;
    }
    return(1);
}
void    push_to_b(t_data *stack)
{
    int i;
    int k;
    int z;
    
    z = 0;
    i = 0;
    k = 0;


    while (!ft_check_sort(stack))
    {
        if (stack->index[i] >= k && stack->index[i] < k + 12)
        {
            k = stack->index[i];
            ra_instruction(stack, z);
        }
        else
            pb_instruction(stack);
    }  
}

void	initialiser(int *t)
{
    t[MINA] = 0;
    t[MAXA] = 0;
	t[NBRINSA] = 0;
	t[NBRINSB] = 0;
	t[NBRINSAB] = 0;
	t[LENA] = 0;
	t[LENB] = 0;
	t[NBA] = 0;
	t[NBB] = 0;
	t[NBAB] = MAXIM;
	t[FROMUPA] = 1;
	t[FROMUPB] = 1;
	t[UPA] = 0;
	t[UPB] = 0;
}

void	size(t_data *stack, int *t)
{
    int     i;

    i = 0;
	t[MINA] = stack->index[0];
	t[MAXA] = stack->index[0];
	t[LENA] = 0;
	t[LENB] = 0;
	while (i < stack->len_a)
	{
		if (stack->index[i] < t[MINA])
		{
            t[MINA] = stack->index[i];
            printf("%d\n", t[MINA]);
		
        }else if (stack->index[i] > t[MAXA])
			t[MAXA] = stack->index[i];
		i++;
	}
    t[LENA] = stack->len_a;
	t[LENB] = stack->len_b;	
}

void	ft_min(int *t, int *a)
{
    int i;

    i = 0;
	t[FROMUPA] = 1;
	while (a[i] != t[MINA])
	{
		t[NBRINSA]++;
        i++;
	}
}

void	ft_max(int *t, t_data *a, int *v)
{
    int i;

	t[FROMUPA] = 1;
    i = 0;
	while (a->index[i] != t[MAXA])
	{
		t[NBRINSA]++;
		i++;
	}
	if (t[NBRINSA] > (t[LENA] / 2))
		*v = -1;
	else
		*v = 1;
}

void	ft_mid(int *t, t_data *a, int b)
{
    int i;

    i = 0;
	t[NBRINSA] = 1;
	t[FROMUPA] = 1;
	while (i < a->len_a && !(b < a->index[i + 1] && b > a->index[i]))
	{
		t[NBRINSA]++;
		i++;
	}
	if (i > a->len_a)
		t[NBRINSA] = 0;
}

void	min_instructions(int *t, int nb)
{
	t[UPA] = t[FROMUPA];
	t[UPB] = t[FROMUPB];
	t[NBA] = t[NBRINSA];
	t[NBB] = nb;
	t[NBAB] = t[NBRINSAB];
}

void	number_of_instructions(int *t, int v, int nb)
{
	if (t[NBRINSA] > (t[LENA] / 2))
	{
		t[FROMUPA] = 0;
		t[NBRINSA] = t[LENA] - t[NBRINSA];
	}
	if (nb > (t[LENB] / 2))
	{	
		t[FROMUPB] = 0;
		nb = t[LENB] - nb;
	}
	t[NBRINSA] += v;
	if (t[FROMUPB] == t[FROMUPA])
	{
		if (t[NBRINSA] > nb)
			t[NBRINSAB] = t[NBRINSA];
		else
			t[NBRINSAB] = nb;
	}
	else
		t[NBRINSAB] = t[NBRINSA] + nb;
	if (t[NBAB] > t[NBRINSAB])
		min_instructions(t, nb);
}

void	find_element(int *t, t_data *stack)
{
	int		v;
	int		nb;
    int     i;

	nb = 0;
    i = 0;
	while (i < stack->len_b)
	{
		t[FROMUPB] = 1;
		v = 0;
		t[NBRINSA] = 0;
		if (stack->b[i] < t[MINA])
			ft_min(t, stack->index);
		else if (stack->b[i] > t[MAXA])
			ft_max(t, stack, &v);
		else
			ft_mid(t, stack, stack->b[i]);
		number_of_instructions(t, v, nb);
		i++;
		nb++;
	}
}

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

void	push_to_a(t_data *stack)
{
	int		t[14];

	while (stack->len_b > 0)
	{
		initialiser(t);
		size(stack, t);
		find_element(t, stack);
        // printf("%d\n", stack->b[0]);
        // printf("%d\n", stack->b[1]);
        // printf("MINA--%d\n",t[0]);
        // printf("MAXA--%d\n",t[1]);
        // printf("LENA--%d\n",t[2]);
        // printf("LENB--%d\n",t[3]);
        // printf("NBA--%d\n",t[4]);
        // printf("NBB--%d\n",t[5]);
        // printf("NBAB--%d\n",t[6]);
        // printf("FROMUPA--%d\n",t[7]);
        // printf("FROMUPB--%d\n",t[8]);
        // printf("NBRINSA--%d\n",t[9]);
        // printf("NBRINSB--%d\n",t[10]);
        // printf("NBRINSAB--%d\n",t[11]);
        // printf("UPA--%d\n",t[12]);
        // printf("UPB--%d\n",t[13]);
		actions(t, stack);
	}
}

void    final_touch(t_data *stack)
{
    int i;
    int moyenne;
    int k;
    
    k = 0;
    i = 0;
    moyenne = stack->len_a/2;
    while (i <= stack->len_a)
    {
        if (stack->index[i] == 0)
            break;
        i++;
    }
    if (i > moyenne)
    {
        while (i <= 0)
        {
            rra_instruction(stack, k);
            i--;
        }
    }
    else
    {
        while (i < 0)
        {
            ra_instruction(stack, k);
            i--;
        }
    }
    
}

int     main(int argc, char **argv)
{
    t_data *stack;
    // int i;

    // i = 0;
    stack = malloc(sizeof(t_data));
    stack->len_a = argc - 2;
    stack->len_b = 0;
    stack->max_len = argc - 2;
    stack->a = malloc(sizeof(int) * (argc));
    stack->b = malloc(sizeof(int) *  (argc));
    stack->sorted = malloc(sizeof(int) * (argc));
    stack->index = malloc(sizeof(int) * (argc));
    ft_remplir(stack, argc, argv);
    ft_sort_table(stack);
    fillindex(stack);
    // while (i < stack->len_a)
    // {
    //     printf("a---%d\n", stack->index[i]);
    //     i++;
    // }
    // i = 0;
    // while (i < stack->len_b)
    // {
    //     printf("b---%d\n", stack->b[i]);
    //     i++;
    // }
    // pb_instruction(stack);
    // pb_instruction(stack);
    // pb_instruction(stack);
    // i = 0;
    // while (i < stack->len_a)
    // {
    //     printf("a---%d\n", stack->index[i]);
    //     i++;
    // }
    // i = 0;
    // while (i < stack->len_b)
    // {
    //     printf("b---%d\n", stack->b[i]);
    //     i++;
    // }
    push_to_b(stack);
    stack->len_a++;
    push_to_a(stack);
    final_touch(stack);
    ft_free(stack);    
    return (0);
}