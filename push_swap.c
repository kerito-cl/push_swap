/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:40:38 by mquero            #+#    #+#             */
/*   Updated: 2024/12/06 16:58:58 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_pop(int *arr, int *count)
{
    int n;

    if (*count != 0)
        n = arr[*count - 1];
    *count = *count - 1;
    return (n);
}

void ft_push(int *arr, int *count, int p)
{
    int n;

    if (*count != 0)
        arr[*count - 1] = p;
    else
    *count = *count + 1;
}
void ft_push_b(int *arr, int *count, int p)
{
    int n;

    arr[*count] = p;
    *count = *count + 1;
}

void ft_swap(int *arr, int *count)
{
    int temp;

    if (*count >= 2)
    {
        temp = arr[*count - 1];
        arr[*count - 1] =  arr[*count - 2];
        arr[*count - 2] = temp;
    }
}

void p_first_2(t_stack *s)
{
    int pop1;
    int pop2;

    pop1 = ft_pop(s->a, &s->count_a);
    ft_push_b(s->b, &s->count_b, pop1);
    write (1, "pb\n", 3);
    pop2 = ft_pop(s->a, &s->count_a);
    ft_push_b(s->b, &s->count_b, pop2);
    write (1, "pb\n", 3);
    if (s->b[0] > s->b[1])
    {
        s->max_b = s->b[0];
        s->min_b = s->b[1];
    }
    else
    {
        s->max_b = s->b[1];
        s->min_b = s->b[0];
    }
    s->mov+= 2;
}

int get_index(t_stack *s, int n)
{
    int *temp;
    int i;
    int j;
    int k;
    
    i = s->count_b - 1;
    temp = s->b;
    k = 0;
    if (n < s->min_b || n > s->max_b)
    {
        while(i >= 0)
        {
            if (s->b[i] == s->max_b)
                return (i);
            i--;
        }
    }
    while(i >= 0)
    {
        if(n > temp[i])
        {
            k = i;
            while (i >= 0)
            {
                if(temp[i] > temp[k] && n > temp[i])
                    k = i;
                i--;
            }
        }
        i--;
    }
    return (k);
}

int get_cost(int *a, int k, int count, int *check)
{
        if(k > ((count - 1) - k))
        {
            *check = 0;
            return ((count - 1) - k);
        }
        else
        {
            *check = 1;
            return(k + 1);
        }
}

int check_cost(t_stack *s)
{
    int i;
    int j;
    int prev;
    int index;
    int total;

    i = s->count_a - 1;
    s->cost_to_b = 0;
    s->cost_a = 0;
    while (i >= 0)
    {
        index = get_index(s, s->a[i]);
        s->cost_to_b = get_cost(s->b, index, s->count_b, &s->check1);
        s->cost_a = get_cost(s->a, i ,s->count_a, &s->check2);
        if (s->check1 == s->check2)
        {
            if (s->cost_a > s->cost_to_b)
                s->cost_to_b = s->cost_a;
        }
        else
            s->cost_to_b = s->cost_to_b + s->cost_a;
        if (i == s->count_a - 1 || s->cost_to_b < s->totalcost)
        {
            j = i;
            s->totalcost = s->cost_to_b;
        }
        prev = s->cost_to_b;
        i--;
    }
    return (j);
}


void algorithm(t_stack *s)
{
    int j;
    int popped;
    int target;
    int index;


    s->count_b = 0;
    p_first_2(s);
    while (s->count_a > 3)
    {
        target = check_cost(s);
        index = get_index(s, s->a[target]);
        s->cost_to_b = get_cost(s->b, index, s->count_b, &s->check1);
        s->cost_a = get_cost(s->a, target ,s->count_a, &s->check2);
        while (s->totalcost > 0)
        {
            if (s->check1 == s->check2 && s->check1 == 1)
            {
                if (s->cost_a > 0 && s->cost_to_b > 0)
                {
                    rotate_reverse(s->a, &s->count_a);
                    rotate_reverse(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->cost_a-= 1;
                    s->totalcost -=1;
                    write (1, "rrr\n", 4);
                }
                if (s->cost_a == 0 && s->cost_to_b > 0)
                {
                    rotate_reverse(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->totalcost-=1;
                    write (1, "rrb\n", 4);
                }
                if (s->cost_to_b == 0 && s->cost_a > 0)
                {
                    rotate_reverse(s->a, &s->count_a);
                    s->cost_a-= 1;
                    s->totalcost-=1;
                    write (1, "rra\n", 4);
                }
            }
            else if (s->check1 == s->check2 && s->check1 == 0)
            {
                if (s->cost_a > 0 && s->cost_to_b > 0)
                {
                    rotate(s->a, &s->count_a);
                    rotate(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->cost_a-= 1;
                    s->totalcost -=1;
                    write (1, "rr\n", 3);
                }
                if (s->cost_a == 0 && s->cost_to_b > 0)
                {
                    rotate(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->totalcost-=1;
                    write (1, "rb\n", 3);
                }
                if (s->cost_to_b == 0 && s->cost_a > 0)
                {
                    rotate(s->a, &s->count_a);
                    s->cost_a-= 1;
                    s->totalcost-=1;
                    write (1, "ra\n", 3);
                }
            }
            else if (s->check1  == 1 && s->check2 == 0)
            {
                if (s->cost_a > 0 && s->cost_to_b > 0)
                {
                    rotate_reverse(s->b, &s->count_b);
                    rotate(s->a, &s->count_a);
                    s->cost_to_b-= 1;
                    s->cost_a-= 1;
                    s->totalcost -=2;
                    write (1, "rrb\n", 4);
                    write (1, "ra\n", 3);
                }
                if (s->cost_a == 0 && s->cost_to_b > 0)
                {
                    rotate_reverse(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->totalcost-=1;
                    write (1, "rrb\n", 3);
                }
                if (s->cost_to_b == 0 && s->cost_a > 0)
                {
                    rotate(s->a, &s->count_a);
                    s->cost_a-= 1;
                    s->totalcost-=1;
                    write (1, "ra\n", 3);
                }
            }
            else if (s->check2  == 1 && s->check1 == 0)
            {
                if (s->cost_a > 0 && s->cost_to_b > 0)
                {
                    rotate_reverse(s->a, &s->count_a);
                    rotate(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->cost_a-= 1;
                    s->totalcost -=2;
                    write (1, "rra\n", 4);
                    write (1, "rb\n", 3);
                }
                if (s->cost_a == 0 && s->cost_to_b > 0)
                {
                    rotate(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->totalcost-=1;
                    write (1, "rb\n", 3);
                }
                if (s->cost_to_b == 0 && s->cost_a > 0)
                {
                    rotate_reverse(s->a, &s->count_a);
                    s->cost_a-= 1;
                    s->totalcost-=1;
                    write (1, "rra\n", 4);
                }
            }
        }
        popped = ft_pop(s->a, &s->count_a);
        ft_push_b(s->b, &s->count_b, popped);
        if (s->b[s->count_b - 1] < s->min_b)
            s->min_b = s->b[s->count_b - 1];
        else if (s->b[s->count_b - 1] > s->max_b)
            s->max_b = s->b[s->count_b -1];
        write (1, "pb\n", 3);
    }
    j = 0;
    while (s->max_b != s->b[j])
        j++;
    s->cost_max_to_top = get_cost(s->b, j, s->count_b, &s->check1);
    while (s->cost_max_to_top > 0)
    {
        if (s->check1 == 1)
            rotate_reverse(s->b, &s->count_b);
        else
            rotate(s->b, &s->count_b);
        s->cost_max_to_top-=1;
    }
}

int main(int arg, char **args)
{
    t_stack s;

    int i = 0;
    if (arg < 2)
        return (0);
    if (arg == 2)
        s.a = create_array_op1(args[1], &s.count_a);
    if (arg > 2)
    {
        s.a = create_array_op2(arg,args);
        s.count_a = arg - 1;
    }
    s.b = (int *)malloc(sizeof(int) * s.count_a);
    algorithm(&s);
    printf("\n");
    i =0;
    while (i < s.count_b)
    {
        printf(" %d ", s.b[i]);
        i++;
    }
    i =0;
    printf("\n");
    while (i < s.count_a)
    {
        printf(" %d ", s.a[i]);
        i++;
    }
}
