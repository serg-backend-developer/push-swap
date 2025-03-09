#include "../include/push_swap.h"

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*last_node;

	last_node = stack;
	while (last_node && last_node->next)
		last_node = last_node->next;
	return (last_node);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 1;
	while (stack->next)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

static int	is_valid_integer_string(char *str)
{
	int	index;
	int	length;

	index = 0;
	if (str[0] == '-')
		index++;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	length = ft_strlen(str);
	if ((str[0] != '-' && length > 10) || (str[0] == '-' && length > 11))
		return (0);
	if (length == 10 && str[0] != '-' && ft_strncmp(str, "2147483647", 10) > 0)
		return (0);
	if (length == 11 && str[0] == '-' && \
			ft_strncmp(str + 1, "2147483648", 10) > 0)
		return (0);
	return (1);
}

static int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	populate_stack(t_stack **stack, char **input_strings)
{
	t_stack	*last_node;
	t_stack	*new_node;

	last_node = get_last_node(*stack);
	while (*input_strings)
	{
		if (!is_valid_integer_string(*input_strings))
			free_stack_and_exit(*stack, 1);
		new_node = malloc(sizeof(*new_node));
		if (!new_node)
			free_stack_and_exit(*stack, 1);
		new_node->value = ft_atoi(*input_strings);
		new_node->next = NULL;
		if (has_duplicate(*stack, new_node->value))
			free_stack_and_exit(*stack, 1);
		if (!*stack)
			*stack = new_node;
		if (last_node)
			last_node->next = new_node;
		last_node = new_node;
		input_strings++;
	}
}
