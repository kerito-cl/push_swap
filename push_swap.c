/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:40:38 by mquero            #+#    #+#             */
/*   Updated: 2024/12/12 16:03:26 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *s, int n)
{
	int	i;
	int	k;

	i = s->count_b - 1;
	k = -1;
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
			if (k == -1 || s->b[i] > s->b[k])
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
	s->max_b = 0;
	s->min_b = 0;
	if (s->count_a > 3)
		p_first_2(s);
	while (s->count_a > 3)
	{
		target = check_cost(s);
		index = get_index(s, s->a[target]);
		s->cost_to_b = get_cost(index, s->count_b, &s->check1);
		s->cost_a = get_cost(target, s->count_a, &s->check2);
		push_to_b(s);
	}
	if (s->count_b > 1)
		max_to_top(s);
	sort_a_stack(s);
	push_to_a(s);
}

int	main(int arg, char **args)
{
	t_stack	s;

	if (arg < 2 || ft_strlen(args[1]) == 0)
		return (0);
	parse(arg, args, &s);
	check_if_repeated(&s);
	if (check_if_sorted(&s) == 0)
	{
		free(s.a);
		return (0);
	}
	s.b = (int *)malloc(sizeof(int) * s.count_a);
	if (s.b == NULL)
	{
		free(s.a);
		return (1);
	}
	algorithm(&s);
	free(s.a);
	free(s.b);
}
