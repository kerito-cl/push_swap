/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:05:04 by mquero            #+#    #+#             */
/*   Updated: 2024/12/08 19:18:54 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   check_nums_case_1(char *str)
{
    char    **split;
    int i;

    i = 0;
    while (str[i])
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
                return(0);
        i++;
    }
    split = ft_split(str, ' ');
    i = 0;
    while (split[i])
    {
        if (ft_atoi(split[i]) > INT_MAX || ft_atoi(split[i]) < INT_MIN)
        {
            freesplit(split);
            return(0);
        }
        i++;
    }
    freesplit(split);
    return (1);
}

int   check_nums_case_1(char **str)
{
    int i;
    int j;

    i = 0;
    while (str[i + 1])
    {
        j = 0;
        while (str[i + 1][j])
        {
            if ((str[i + 1] < '0' || str[i + 1] > '9') && str[i + 1][j] != ' ')
                    return(0);
            j++;
        }
        i++;
    }
    i = 0;
    while (str[i])
    {
        if (ft_atoi(str[i + 1]) > INT_MAX || ft_atoi(str[i + 1]) < INT_MIN)
            return(0);
        i++;
    }
    return (1);
}

int parse(int arg, char **args, t_stack *s)
{
    int i;
    int j;

	if (arg == 2)
    {
        if (check_nums_case_1(args[1]) == 0)
        {
		    write(1, "Error\n", 6);
            exit (0);
        }
		s->a = create_array_op1(args[1], &s->count_a);
        if (s->a == NULL)
            exit (0);
    }
	else if (arg > 2)
	{
        if (check_nums_case_1(args[1]) == 0)
        {
		    write(1, "Error\n", 6);
            exit (0);
        }
		s->a = create_array_op2(arg, args);
		if (s->a == NULL)
			exit (0);
		s->count_a = arg - 1;
	}
}
