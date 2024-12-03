/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:40:38 by mquero            #+#    #+#             */
/*   Updated: 2024/12/03 18:45:03 by mquero           ###   ########.fr       */
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
    *count = *count + 1;
}


int main(int arg, char **args)
{
    t_stack stack;

    int i = 0;
    if (arg < 2)
        return (0);
    if (arg == 2)
        stack.a = create_array_op1(args[1], &stack.count);
    if (arg > 2)
    {
        stack.a = create_array_op2(arg,args);
        stack.count = arg - 1;
    }
    printf(" count %d\n", stack.count);
    int popped;
    popped = ft_pop(stack.a, &stack.count);
    printf(" item popped %d\n",popped);
    printf(" last element %d\n",stack.a[stack.count - 1]);
    printf(" count %d\n",stack.count);
    ft_push(stack.a, &stack.count, popped);
    printf(" item pushed %d\n",stack.a[stack.count - 1]);
    printf(" new countt %d\n",stack.count);
}
