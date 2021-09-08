#include "push_swap.h"

/*void ft_allocate(t_data stack, t_sort the, int argc)
{
    the.moyenne = malloc(sizeof(int));
    the.first = malloc(sizeof(int));
    the.second = malloc(sizeof(int));
    the.third = malloc(sizeof(int));
    the.one = malloc(sizeof(int));
    the.two = malloc(sizeof(int));
    the.three = malloc(sizeof(int));
    the.first_b = malloc(sizeof(int));
    the.second_b = malloc(sizeof(int));
    the.third_b = malloc(sizeof(int));
    the.one_b = malloc(sizeof(int));
    the.two_b = malloc(sizeof(int));
    the.three_b = malloc(sizeof(int));
    stack.a = malloc(sizeof(int) * (argc));
    stack.b = malloc(sizeof(int) *  (argc));
    stack.len_a = malloc(sizeof(int));
    stack.len_b = malloc(sizeof(int));
    *stack.len_a = argc - 2;
    *stack.len_b = 0;
    *the.moyenne = (argc - 2) / 2;
}
*/
void ft_sort_first(t_data stack, t_sort the)
{
    int i = 0;
    int tmp;
    while (i < *stack.len_a)
    {
        if (stack.a[i] < stack.a[i + 1])
        {
            if (i == 0)
            {
                *the.first = stack.a[i];
                *the.one = i;
            }
            tmp = stack.a[i];
            if (*the.first > tmp)
            {
                *the.first = tmp;
                *the.one = i;
                //printf("the one = == =%d\n", *the.one);
            }
        }
        else if (stack.a[i] > stack.a[i + 1])
        {
             if (i == 0)
            {
                *the.first = stack.a[i + 1];
                *the.one = i + 1;
            }
            tmp = stack.a[i + 1];
            if (*the.first > tmp)
            {
                *the.first = tmp;
                *the.one = i;
                //printf("the one = == =%d\n", *the.one);
            }
        }
        
        i++;
    }
    
}

void ft_9elleb(t_data stack, t_sort the)
{
    ft_sort_first(stack,the);
    //ft_sort_second(stack,the);
    *the.moyenne = *stack.len_a/2;
    //ft_sort_third(stack,the);
}