/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:48:36 by mquero            #+#    #+#             */
/*   Updated: 2024/12/12 16:04:46 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	ft_atoi(const char *str)
{
	int		i;
	int		n;
	int64_t	hold;

	i = 0;
	n = 1;
	hold = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			n = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		hold = (hold * 10) + (str[i] - '0');
		if (hold < 0 && n == 1)
			return (-1);
		else if (hold < 0 && n == -1)
			return (0);
		i++;
	}
	return (hold * n);
}

int	check_errors(char **str, int i, int *j)
{
	if (str[i][*j] == '-' || str[i][*j] == '+')
		*j = *j + 1;
	if (((str[i][*j] < '0' || str[i][*j] > '9') && str[i][*j] != ' ') || *j > 11
		|| ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
		return (0);
	else
		return (1);
}

int	check_errors2(char **str, int i, int *j)
{
	if (str[i][*j] == '-' || str[i][*j] == '+')
		*j = *j + 1;
	if (((str[i][*j] < '0' || str[i][*j] > '9')) || *j > 11
		|| ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
		return (0);
	else
		return (1);
}
