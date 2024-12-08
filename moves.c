/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:13:13 by mquero            #+#    #+#             */
/*   Updated: 2024/12/08 15:16:40 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_stack(t_stack *s)
{
	set_max(s);
	if (s->a[2] == s->max_a)
	{
		rotate(s->a, &s->count_a);
		write(1, "ra\n", 3);
	}
	if (s->a[0] < s->a[2])
	{
		rotate_reverse(s->a, &s->count_a);
		write(1, "rra\n", 4);
	}
	if (s->a[1] < s->a[2] || s->max_a == s->a[1])
	{
		ft_swap(s->a, &s->count_a);
		write(1, "sa\n", 3);
	}
	if (s->a[2] == s->max_a)
	{
		rotate(s->a, &s->count_a);
		write(1, "ra\n", 3);
	}
	s->min_a = s->a[2];
	s->mid_a = s->a[1];
}

void	push_to_a(t_stack *s)
{
	int	i;
	int	lock;

	lock = 0;
	i = s->count_b - 1;
	while (i >= 0)
	{
		case_for_a_stack(s, &lock, &i);
		ft_push(s->a, &s->count_a, ft_pop(s->b, &s->count_b));
		write(1, "pa\n", 3);
		i--;
	}
	if (s->a[0] < s->a[s->count_a - 1])
	{
		rotate_reverse(s->a, &s->count_a);
		write(1, "rra\n", 4);
	}
}

void	push_to_b(t_stack *s)
{
	while (s->totalcost > 0)
	{
		if (s->check1 == s->check2 && s->check1 == 1)
			case1(s);
		else if (s->check1 == s->check2 && s->check1 == 0)
			case2(s);
		else if (s->check1 == 1 && s->check2 == 0)
			case3(s);
		else if (s->check2 == 1 && s->check1 == 0)
			case4(s);
	}
	ft_push(s->b, &s->count_b, ft_pop(s->a, &s->count_a));
	if (s->b[s->count_b - 1] < s->min_b)
		s->min_b = s->b[s->count_b - 1];
	else if (s->b[s->count_b - 1] > s->max_b)
		s->max_b = s->b[s->count_b - 1];
	write(1, "pb\n", 3);
}

void	max_to_top(t_stack *s)
{
	int	j;

	j = 0;
	while (s->max_b != s->b[j])
		j++;
	s->cost_max_to_top = get_cost(j, s->count_b, &s->check1);
	while (s->cost_max_to_top > 0)
	{
		if (s->check1 == 1)
		{
			rotate_reverse(s->b, &s->count_b);
			write(1, "rrb\n", 4);
		}
		else
		{
			rotate(s->b, &s->count_b);
			write(1, "rb\n", 3);
		}
		s->cost_max_to_top -= 1;
	}
}

void	p_first_2(t_stack *s)
{
	int	pop1;
	int	pop2;

	pop1 = ft_pop(s->a, &s->count_a);
	ft_push(s->b, &s->count_b, pop1);
	write(1, "pb\n", 3);
	pop2 = ft_pop(s->a, &s->count_a);
	ft_push(s->b, &s->count_b, pop2);
	write(1, "pb\n", 3);
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
}
