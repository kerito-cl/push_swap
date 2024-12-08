/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:48 by mquero            #+#    #+#             */
/*   Updated: 2024/12/08 15:16:08 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int	ft_pop(int *arr, int *count)
{
	int	n;

	if (*count != 0)
		n = arr[*count - 1];
	*count = *count - 1;
	return (n);
}

void	ft_push(int *arr, int *count, int p)
{
	arr[*count] = p;
	*count = *count + 1;
}

void	ft_swap(int *arr, int *count)
{
	int	temp;

	if (*count >= 2)
	{
		temp = arr[*count - 1];
		arr[*count - 1] = arr[*count - 2];
		arr[*count - 2] = temp;
	}
}

void	set_max(t_stack *s)
{
	int	i;

	i = 0;
	s->max_a = s->a[i];
	while (i < s->count_a - 1)
	{
		i++;
		if (s->max_a < s->a[i])
			s->max_a = s->a[i];
	}
}
