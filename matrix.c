/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:04:18 by mquero            #+#    #+#             */
/*   Updated: 2024/12/02 18:04:02 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(char *line)
{
	int		i;
	int		count;
	char	**split;

	count = 0;
	split = ft_split(line, ' ');
	while (split[count])
		count++;
	freesplit(split);
	return (count);
}

int	*build_row(char *line)
{
	int		i;
	int		j;
	int		*row;
	int		count;
	char	**split;

	count = count_numbers(line);
	row = (int *)malloc(count * sizeof(int));
	if (row == NULL || count == 0)
	{
		free(row);
		return (NULL);
	}
	split = ft_split(line, ' ');
	j = 0;
	i = 0;
	while (split[i])
	{
		row[j] = ft_atoi(split[i]);
		j++;
		i++;
	}
	freesplit(split);
	return (row);
}

int	count_rows(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	if (line == NULL || count_numbers(line) == 0)
		return (0);
	while (line != NULL)
	{
		free(line);
		count++;
		line = get_next_line(fd);
		if (line != NULL && count_numbers(line) == 0)
			return (0);
	}
	return (count);
}

int	**create_matrix(int fd, char *map)
{
	int		**matrix;
	char	*line;
	int		i;
	int		count;

	i = 0;
	count = count_rows(fd);
	matrix = (int **)malloc(sizeof(int *) * count);
	fd = close_and_read(fd, map);
	while (i < count)
	{
		line = get_next_line(fd);
		matrix[i] = build_row(line);
		free(line);
		i++;
	}
	return (matrix);
}
