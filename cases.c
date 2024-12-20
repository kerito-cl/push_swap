/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:23:59 by mquero            #+#    #+#             */
/*   Updated: 2024/12/08 15:11:17 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case1(t_stack *s)
{
	if (s->cost_a > 0 && s->cost_to_b > 0)
	{
		rotate_reverse(s->a, &s->count_a);
		rotate_reverse(s->b, &s->count_b);
		s->cost_to_b -= 1;
		s->cost_a -= 1;
		s->totalcost -= 1;
		write(1, "rrr\n", 4);
	}
	if (s->cost_a == 0 && s->cost_to_b > 0)
	{
		rotate_reverse(s->b, &s->count_b);
		s->cost_to_b -= 1;
		s->totalcost -= 1;
		write(1, "rrb\n", 4);
	}
	if (s->cost_to_b == 0 && s->cost_a > 0)
	{
		rotate_reverse(s->a, &s->count_a);
		s->cost_a -= 1;
		s->totalcost -= 1;
		write(1, "rra\n", 4);
	}
}

void	case2(t_stack *s)
{
	if (s->cost_a > 0 && s->cost_to_b > 0)
	{
		rotate(s->a, &s->count_a);
		rotate(s->b, &s->count_b);
		s->cost_to_b -= 1;
		s->cost_a -= 1;
		s->totalcost -= 1;
		write(1, "rr\n", 3);
	}
	if (s->cost_a == 0 && s->cost_to_b > 0)
	{
		rotate(s->b, &s->count_b);
		s->cost_to_b -= 1;
		s->totalcost -= 1;
		write(1, "rb\n", 3);
	}
	if (s->cost_to_b == 0 && s->cost_a > 0)
	{
		rotate(s->a, &s->count_a);
		s->cost_a -= 1;
		s->totalcost -= 1;
		write(1, "ra\n", 3);
	}
}

void	case3(t_stack *s)
{
	if (s->cost_a > 0 && s->cost_to_b > 0)
	{
		rotate_reverse(s->b, &s->count_b);
		rotate(s->a, &s->count_a);
		s->cost_to_b -= 1;
		s->cost_a -= 1;
		s->totalcost -= 2;
		write(1, "rrb\n", 4);
		write(1, "ra\n", 3);
	}
	if (s->cost_a == 0 && s->cost_to_b > 0)
	{
		rotate_reverse(s->b, &s->count_b);
		s->cost_to_b -= 1;
		s->totalcost -= 1;
		write(1, "rrb\n", 4);
	}
	if (s->cost_to_b == 0 && s->cost_a > 0)
	{
		rotate(s->a, &s->count_a);
		s->cost_a -= 1;
		s->totalcost -= 1;
		write(1, "ra\n", 3);
	}
}

void	case4(t_stack *s)
{
	if (s->cost_a > 0 && s->cost_to_b > 0)
	{
		rotate_reverse(s->a, &s->count_a);
		rotate(s->b, &s->count_b);
		s->cost_to_b -= 1;
		s->cost_a -= 1;
		s->totalcost -= 2;
		write(1, "rra\n", 4);
		write(1, "rb\n", 3);
	}
	if (s->cost_a == 0 && s->cost_to_b > 0)
	{
		rotate(s->b, &s->count_b);
		s->cost_to_b -= 1;
		s->totalcost -= 1;
		write(1, "rb\n", 3);
	}
	if (s->cost_to_b == 0 && s->cost_a > 0)
	{
		rotate_reverse(s->a, &s->count_a);
		s->cost_a -= 1;
		s->totalcost -= 1;
		write(1, "rra\n", 4);
	}
}

void	case_for_a_stack(t_stack *s, int *lock, int *i)
{
	if (s->b[*i] < s->max_a && *lock == 0)
	{
		rotate_reverse(s->a, &s->count_a);
		write(1, "rra\n", 4);
		*lock = *lock + 1;
	}
	if (s->b[*i] < s->mid_a && *lock == 1)
	{
		rotate_reverse(s->a, &s->count_a);
		write(1, "rra\n", 4);
		*lock = *lock + 1;
	}
	if (s->b[*i] < s->min_a && *lock == 2)
	{
		s->min_a = s->b[*i];
		rotate_reverse(s->a, &s->count_a);
		write(1, "rra\n", 4);
		*lock = *lock + 1;
	}
}
