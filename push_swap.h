#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>


typedef struct s_stack
{
	int		*a;
	int		*b;
	int		count;
}			t_stack;

void	freesplit(char **strs);
char	**ft_split(char const *s, char c);
int	*create_array_op1(char *args, int *count);
int	*create_array_op2(int arg, char **args);
int	ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
