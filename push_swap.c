/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:40:38 by mquero            #+#    #+#             */
/*   Updated: 2024/12/08 18:02:45 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *s, int n)
{
	int	i;
	int	k;

	i = s->count_b - 1;
	k = 0;
	if (n < s->min_b || n > s->max_b)
	{
		while (i >= 0)
		{
			if (s->b[i] == s->max_b)
				return (i);
			i--;
		}
	}
	while (i >= 0)
	{
		if (n > s->b[i])
		{
			if (k == 0 || s->b[i] > s->b[k])
				k = i;
		}
		i--;
	}
	return (k);
}

int	get_cost(int k, int count, int *check)
{
	if (k > ((count - 1) - k))
	{
		*check = 0;
		return ((count - 1) - k);
	}
	else
	{
		*check = 1;
		return (k + 1);
	}
}

int	check_cost(t_stack *s)
{
	int	i;
	int	j;
	int	index;

	i = s->count_a - 1;
	while (i >= 0)
	{
		index = get_index(s, s->a[i]);
		s->cost_to_b = get_cost(index, s->count_b, &s->check1);
		s->cost_a = get_cost(i, s->count_a, &s->check2);
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
		i--;
	}
	return (j);
}

void	algorithm(t_stack *s)
{
	int	target;
	int	index;

	s->count_b = 0;
	p_first_2(s);
	while (s->count_a > 3)
	{
		target = check_cost(s);
		index = get_index(s, s->a[target]);
		s->cost_to_b = get_cost(index, s->count_b, &s->check1);
		s->cost_a = get_cost(target, s->count_a, &s->check2);
		push_to_b(s);
	}
	max_to_top(s);
	sort_a_stack(s);
	push_to_a(s);
}

int	main(int arg, char **args)
{
	t_stack	s;

	if (arg < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (arg == 2)
		s.a = create_array_op1(args[1], &s.count_a);
	if (arg > 2)
	{
		s.a = create_array_op2(arg, args);
		if (s.a == NULL)
			return (0);
		s.count_a = arg - 1;
	}
	s.b = (int *)malloc(sizeof(int) * s.count_a);
	algorithm(&s);
	free(s.a);
	free(s.b);
}
