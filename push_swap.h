/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:24:40 by mquero            #+#    #+#             */
/*   Updated: 2024/12/12 16:01:02 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	count_a;
	int	count_b;
	int	cost_max_to_top;
	int	check1;
	int	check2;
	int	min_a;
	int	min_b;
	int	max_a;
	int	max_b;
	int	mid_a;
	int	temp;
	int	cost_to_b;
	int	cost_a;
	int	totalcost;
}		t_stack;

void	freesplit(char **strs);
char	**ft_split(char const *s, char c);
int		*create_array_op1(char *args, int *count);
int		*create_array_op2(int arg, char **args);
long	ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	rotate(int *arr, int *count);
void	rotate_reverse(int *arr, int *count);
void	ft_swap(int *arr, int *count);
void	ft_push(int *arr, int *count, int p);
int		ft_pop(int *arr, int *count);
void	case1(t_stack *s);
void	case2(t_stack *s);
void	case3(t_stack *s);
void	case4(t_stack *s);
void	case_for_a_stack(t_stack *s, int *lock, int *i);
void	set_max(t_stack *s);
void	sort_a_stack(t_stack *s);
void	push_to_a(t_stack *s);
void	push_to_b(t_stack *s);
void	max_to_top(t_stack *s);
int		get_cost(int k, int count, int *check);
void	p_first_2(t_stack *s);
void	parse(int arg, char **args, t_stack *s);
int		check_if_sorted(t_stack *s);
int		ft_strlen(char *s);
int		check_errors(char **str, int i, int *j);
int		check_errors2(char **str, int i, int *j);
int		check_if_repeated(t_stack *s);

#endif
