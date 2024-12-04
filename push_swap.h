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
	int		cheapest_a;
	int		cheapest_b;
	int		mov;
	int		min_a;
	int		min_b;
	int		max_a;
	int		max_b;
	int		temp;
}			t_stack;

void	freesplit(char **strs);
char	**ft_split(char const *s, char c);
int	*create_array_op1(char *args, int *count);
int	*create_array_op2(int arg, char **args);
int	ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	rotate(int *arr, int *count);
void	rotate_reverse(int *arr, int *count);

#endif
