/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:05:04 by mquero            #+#    #+#             */
/*   Updated: 2024/12/12 16:05:15 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_if_repeated(t_stack *s)
{
	int	i;
	int	j;

	i = s->count_a - 1;
	while (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (s->a[i] == s->a[j])
			{
				write(2, "Error\n", 6);
				free(s->a);
				exit(0);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int	check_nums_case_1(char *str)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(str, ' ');
	if (split == NULL)
		return (2);
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (check_errors(split, i, &j) == 0)
			{
				freesplit(split);
				return (0);
			}
			j++;
		}
		i++;
	}
	freesplit(split);
	return (1);
}

int	check_nums_case_2(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1])
	{
		j = 0;
		while (str[i + 1][j])
		{
			if (check_errors2(str, i + 1, &j) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	parse(int arg, char **args, t_stack *s)
{
	if (arg == 2)
	{
		if (check_nums_case_1(args[1]) == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else if (check_nums_case_1(args[1]) == 2)
			exit(0);
		s->a = create_array_op1(args[1], &s->count_a);
		if (s->a == NULL)
			exit(0);
	}
	else if (arg > 2)
	{
		if (check_nums_case_2(args) == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		s->a = create_array_op2(arg, args);
		if (s->a == NULL)
			exit(0);
		s->count_a = arg - 1;
	}
}
