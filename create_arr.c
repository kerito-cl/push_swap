/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:04:18 by mquero            #+#    #+#             */
/*   Updated: 2024/12/03 20:20:36 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(char *args, char ***split)
{
	int		count;

	count = 0;
	return (count);
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
	while (split[*count])
		*count+=1;
	i = *count - 1;
	arr = (int *)malloc(sizeof(int) * (*count));
	while (i > 0)
	{
		arr[i] = ft_atoi(split[j]);
		i--;
		j++;
	}
	arr[i] = ft_atoi(split[j]);
	freesplit(split);
	return (arr);
}

int	*create_array_op2(int arg, char **args)
{
	int		*arr;
	int		i;
	int		j;

	i = arg - 2;
	j = 0;
	arr = (int *)malloc(sizeof(int) * (arg - 1));
	while (i > 0)
	{
		arr[i] = ft_atoi(args[j + 1]);
		i--;
		j++;
	}
	arr[i] = ft_atoi(args[j + 1]);
	return (arr);
}
