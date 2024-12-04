/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:40:38 by mquero            #+#    #+#             */
/*   Updated: 2024/12/04 16:39:26 by mquero           ###   ########.fr       */
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

void ft_push_a(int *arr, int *count, int p)
{
    int n;

    if (*count != 0)
        arr[*count - 1] = p;
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

void p_first_2(t_stack *stack)
{
    int pop1;
    int pop2;

    pop1 = ft_pop(stack->a, &stack->count_a);
    ft_push_b(stack->b, &stack->count_b, pop1);
    write (1, "pb\n", 3);
    pop2 = ft_pop(stack->a, &stack->count_a);
    ft_push_b(stack->b, &stack->count_b, pop2);
    write (1, "pb\n", 3);
    if (stack->b[0] > stack->b[1])
    {
        stack->max_b = stack->b[0];
        stack->min_b = stack->b[1];
    }
    else
    {
        stack->max_b = stack->b[1];
        stack->min_b = stack->b[0];
    }
    stack->mov+= 2;
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

int check_cost(t_stack stack)
{
    int i;
    int j;
    int c;
    int prev;
    int check;

    i = 0;
    c = 0;
    while (i < stack.count_a)
    {
        c = get_cost(stack.b, get_index(stack.b, stack.a[i],stack.count_b), stack.count_a, &check);
        if (i == 0 || c < prev)
        {
            j = i;
        }
        prev= c;
        i++;
    }
    return (j);

}

void algorithm(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    j = 0;
    stack->count_b = 0;
    p_first_2(stack);
    printf("ITEM TO PUSH %d", stack->a[check_cost(*stack)]);
}

int main(int arg, char **args)
{
    t_stack stack;

    int i = 0;
    if (arg < 2)
        return (0);
    if (arg == 2)
        stack.a = create_array_op1(args[1], &stack.count_a);
    if (arg > 2)
    {
        stack.a = create_array_op2(arg,args);
        stack.count_a = arg - 1;
    }
    stack.b = (int *)malloc(sizeof(int) * stack.count_a);
    /*printf(" count %d\n", stack.count);
    int popped;
    popped = ft_pop(stack.a, &stack.count);
    printf(" item popped %d\n",popped);
    printf(" last element %d\n",stack.a[stack.count - 1]);
    printf(" count %d\n",stack.count);
    ft_push(stack.a, &stack.count, popped);
    printf(" item pushed %d\n",stack.a[stack.count - 1]);
    printf(" new countt %d\n",stack.count);*/
    //ft_swap(stack.a, &stack.count);
    /*printf("INITIAL STAck A \n");
    i =0;
    printf("\nSTAck B \n");
    i =0;
    printf("\nAFTER STAck A \n");
    while (i < stack.count_a)
    {
        printf(" %d ", stack.a[i]);
        i++;
    }*/
    //algorithm(&stack);
    //rotate_reverse(stack.a, &stack.count_a);
    
    algorithm(&stack);
    printf("\n");
    i =0;
    while (i < stack.count_b)
    {
        printf(" %d ", stack.b[i]);
        i++;
    }
    i =0;
    printf("\n");
    while (i < stack.count_a)
    {
        printf(" %d ", stack.a[i]);
        i++;
    }
}
