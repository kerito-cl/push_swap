/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:04:18 by mquero            #+#    #+#             */
/*   Updated: 2024/12/12 16:08:20 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_stack *s)
{
	int	i;
	int	j;

	i = s->count_a - 1;
	while (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (s->a[i] > s->a[j])
				return (1);
			j--;
		}
		i--;
	}
	return (0);
}

int	*create_array_op1(char *args, int *count)
{
	int		*arr;
	char	**split;
	int		i;
	int		j;

	*count = 0;
	j = 0;
	split = ft_split(args, ' ');
	if (split == NULL)
		return (NULL);
	while (split[*count])
		*count += 1;
	i = *count - 1;
	arr = (int *)malloc(sizeof(int) * (*count));
	if (arr == NULL)
		return (NULL);
	while (i > 0)
	{
		arr[i] = (int)ft_atoi(split[j]);
		i--;
		j++;
	}
	arr[i] = ft_atoi(split[j]);
	freesplit(split);
	return (arr);
}

void	rotate(int *arr, int *count)
{
	int	i;
	int	temp;
	int	temp2;

	i = 0;
	temp = arr[i];
	arr[i] = arr[*count - 1];
	i++;
	while (i < *count)
	{
		temp2 = arr[i];
		arr[i] = temp;
		i++;
		temp = temp2;
	}
}

void	rotate_reverse(int *arr, int *count)
{
	int	i;
	int	temp;
	int	temp2;

	i = *count - 1;
	temp = arr[i];
	arr[i] = arr[0];
	i--;
	while (i >= 0)
	{
		temp2 = arr[i];
		arr[i] = temp;
		i--;
		temp = temp2;
	}
}

int	*create_array_op2(int arg, char **args)
{
	int	*arr;
	int	i;
	int	j;

	i = arg - 2;
	j = 0;
	arr = (int *)malloc(sizeof(int) * (arg - 1));
	if (arr == NULL)
		return (NULL);
	while (i > 0)
	{
		arr[i] = ft_atoi(args[j + 1]);
		i--;
		j++;
	}
	arr[i] = ft_atoi(args[j + 1]);
	return (arr);
}
