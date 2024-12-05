/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:40:38 by mquero            #+#    #+#             */
/*   Updated: 2024/12/05 14:50:02 by mquero           ###   ########.fr       */
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

int get_index(int *b, int n, int count)
{
    int *temp;
    int i;
    int j;
    int k;
    
    i = 0;
    temp = b;
    k = 0;
    while (i < count)
    {
        if(n > temp[i])
        {
            k = i;
            while (i < count)
            {
                if(temp[i] > temp[k] && n > temp[i])
                    k = i;
                i++;
            }
        }
        i++;
    }
    return (k);
}

int get_cost(int *a, int k, int count, int *check)
{
        if(k > ((count - 1) - k))
        {
            *check = 1;
            return ((count - 1) - k);
        }
        else
        {
            *check = 0;
            return(k);
        }
}

int check_cost(t_stack *s)
{
    int i;
    int j;
    int prev;
    int index;
    int total;

    i = 0;
    s->cost_to_b = 0;
    s->cost_a = 0;
    while (i < s->count_a)
    {
        index = get_index(s->b, s->a[i],s->count_b);
        s->cost_to_b = get_cost(s->b, index, s->count_b, &s->check1);
        s->cost_a = get_cost(s->a, i ,s->count_a, &s->check2);
        if (s->check1 == s->check2)
        {
            if (s->cost_a > s->cost_to_b)
                s->cost_to_b = s->cost_a;
        }
        else
            s->cost_to_b = s->cost_to_b + s->cost_a;
        if (i == 0 || s->cost_to_b < prev)
        {
            j = i;
            s->totalcost = s->cost_to_b;
        }
        prev = s->cost_to_b;
        i++;
    }
    return (j);
}

void algorithm(t_stack *s)
{
    int i;
    int j;
    int popped;
    int target;
    int index;

    j = 0;
    s->count_b = 0;
    p_first_2(s);
    target = check_cost(s);
    index = get_index(s->b, s->a[target], s->count_b);
    s->cost_to_b = get_cost(s->b, index, s->count_b, &s->check1);
    s->cost_a = get_cost(s->a, target ,s->count_a, &s->check2);
    printf("COST TO B %d\n", s->cost_to_b);
    printf("COST A %d\n", s->cost_a);
    popped = ft_pop(s->a, &s->count_a);
    ft_push_b(s->b, &s->count_b, popped);
    target = check_cost(s);
    index = get_index(s->b, s->a[target], s->count_b);
    s->cost_to_b = get_cost(s->b, index, s->count_a, &s->check1);
    s->cost_a = get_cost(s->a, target ,s->count_a, &s->check2);
    printf("COST TO B %d\n", s->cost_to_b);
    printf("COST A %d\n", s->cost_a);
    popped = ft_pop(s->a, &s->count_a);
    ft_push_b(s->b, &s->count_b, popped);
    //i = get_cost(s->a, target, s->count_a,);
    i = 0;
    /*while (s->count_a > 3)
    {
        target = check_cost(s);
        index = get_index(s->b, s->a[target], s->count_b);
        s->cost_to_b = get_cost(s->b, index, s->count_a, &s->check1);
        s->cost_a = get_cost(s->a, target ,s->count_a, &s->check2);

        while (s->totalcost > 0)
        {
            if (s->check1 == s->check2 && s->check1 == 1)
            {
                if (s->cost_a > 0 && s->b > 0)
                {
                    rotate_reverse(s->a, &s->count_a);
                    rotate_reverse(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->cost_a-= 1;
                    s->totalcost -=1;
                    write (1, "rrr\n", 4);
                }
                if (s->cost_a == 0 && s->b > 0)
                {
                    rotate_reverse(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->totalcost-=1;
                    write (1, "rrb\n", 4);
                }
                if (s->cost_to_b == 0 && s->a > 0)
                {
                    rotate_reverse(s->a, &s->count_a);
                    s->cost_a-= 1;
                    s->totalcost-=1;
                    write (1, "rra\n", 4);
                }
            }
            else if (s->check1 == s->check2 && s->check1 == 0)
            {
                write (1, "rr\n", 3);
                if (s->cost_a > 0 && s->b > 0)
                {
                    rotate(s->a, &s->count_a);
                    rotate(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->cost_a-= 1;
                    s->totalcost -=1;
                    write (1, "rr\n", 3);
                }
                if (s->cost_a == 0 && s->b > 0)
                {
                    rotate(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->totalcost-=1;
                    write (1, "rb\n", 3);
                }
                if (s->cost_to_b == 0 && s->a > 0)
                {
                    rotate(s->a, &s->count_a);
                    s->cost_a-= 1;
                    s->totalcost-=1;
                    write (1, "ra\n", 3);
                }
            }
            else if (s->check1  == 1 && s->check2 == 0)
            {
                if (s->cost_a > 0 && s->b > 0)
                {
                    rotate_reverse(s->b, &s->count_a);
                    rotate(s->a, &s->count_a);
                    s->cost_to_b-= 1;
                    s->cost_a-= 1;
                    s->totalcost -=2;
                    write (1, "rrb\n", 4);
                    write (1, "ra\n", 3);
                }
                if (s->cost_a == 0 && s->b > 0)
                {
                    rotate_reverse(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->totalcost-=1;
                    write (1, "rb\n", 3);
                }
                if (s->cost_to_b == 0 && s->a > 0)
                {
                    rotate(s->a, &s->count_a);
                    s->cost_a-= 1;
                    s->totalcost-=1;
                    write (1, "ra\n", 3);
                }
            }
            else if (s->check2  == 1 && s->check1 == 0)
            {
                if (s->cost_a > 0 && s->b > 0)
                {
                    rotate_reverse(s->a, &s->count_a);
                    rotate(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->cost_a-= 1;
                    s->totalcost -=2;
                    write (1, "rra\n", 4);
                    write (1, "rb\n", 3);
                }
                if (s->cost_a == 0 && s->b > 0)
                {
                    rotate(s->b, &s->count_b);
                    s->cost_to_b-= 1;
                    s->totalcost-=1;
                    write (1, "rb\n", 3);
                }
                if (s->cost_to_b == 0 && s->a > 0)
                {
                    rotate_reverse(s->a, &s->count_a);
                    s->cost_a-= 1;
                    s->totalcost-=1;
                    write (1, "ra\n", 3);
                    printf("IM HERE");
                }
            }
        }
        popped = ft_pop(s->a, &s->count_a);
        ft_push_b(s->b, &s->count_b, popped);
        write (1, "pb\n", 3);
        i++;
    }*/
    
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

    /*printf(" count %d\n", s.count);
    int popped;
    popped = ft_pop(s.a, &s.count);
    printf(" item popped %d\n",popped);
    printf(" last element %d\n",s.a[s.count - 1]);
    printf(" count %d\n",s.count);
    ft_push(s.a, &s.count, popped);
    printf(" item pushed %d\n",s.a[s.count - 1]);
    printf(" new countt %d\n",s.count);*/
    //ft_swap(s.a, &s.count);
    /*printf("INITIAL STAck A \n");
    i =0;
    printf("\nSTAck B \n");
    i =0;
    printf("\nAFTER STAck A \n");
    while (i < s.count_a)
    {
        printf(" %d ", s.a[i]);
        i++;
    }*/
    //algorithm(&s);
    //rotate_reverse(s.a, &s.count_a);
    
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
