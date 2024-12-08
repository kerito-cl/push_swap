#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>


typedef struct s_stack
{
	int		*a;
	int		*b;
	int		count_a;
	int		count_b;
	int		cost_max_to_top;
	int		check1;
	int		check2;
	int		min_a;
	int		min_b;
	int		max_a;
	int		max_b;
	int		mid_a;
	int		temp;
	int		cost_to_b;
	int		cost_a;
	int		totalcost;
}			t_stack;

void	freesplit(char **strs);
char	**ft_split(char const *s, char c);
int	*create_array_op1(char *args, int *count);
int	*create_array_op2(int arg, char **args);
int	ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	rotate(int *arr, int *count);
void	rotate_reverse(int *arr, int *count);
void ft_swap(int *arr, int *count);
void ft_push(int *arr, int *count, int p);
int ft_pop(int *arr, int *count);
void	case1(t_stack *s);
void	case2(t_stack *s);
void	case3(t_stack *s);
void	case4(t_stack *s);
void	set_max(t_stack *s);

#endif
