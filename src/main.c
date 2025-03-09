#include "../include/push_swap.h"

void	free_stack_and_exit(t_stack *stack, int error_flag)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	if (error_flag)
		ft_printf("Error\n");
	exit(0);
}

static void	free_string_array(char **array)
{
	char	**temp;

	temp = array;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	if (array)
		free(array);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tokens;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	argv++;
	while (--argc)
	{
		tokens = ft_split(*argv, ' ');
		populate_stack(&stack_a, tokens);
		free_string_array(tokens);
		argv++;
	}
	sort_stack_a(&stack_a, &stack_b);
	free_stack_and_exit(stack_a, 0);
	return (0);
}
