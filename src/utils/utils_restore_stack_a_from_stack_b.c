#include "../include/push_swap.h"

int	find_min_value(t_stack *stack_a)
{
	int	min;

	min = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min)
			min = stack_a->value;
		stack_a = stack_a->next;
	}
	return (min);
}

int	find_max_value(t_stack *stack_a)
{
	int	max;

	max = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value > max)
			max = stack_a->value;
		stack_a = stack_a->next;
	}
	return (max);
}

static int	find_closest_higher(t_stack **stack_a, int value)
{
	t_stack	*current_node;
	int		closest_higher;

	current_node = *stack_a;
	closest_higher = find_max_value(*stack_a);
	if (value < find_min_value(*stack_a) || value > closest_higher)
	{
		while (current_node)
		{
			if (current_node->value < closest_higher)
				closest_higher = current_node->value;
			current_node = current_node->next;
		}
		return (closest_higher);
	}
	while (current_node)
	{
		if (current_node->value > value && \
				current_node->value < closest_higher)
			closest_higher = current_node->value;
		current_node = current_node->next;
	}
	return (closest_higher);
}

static void	align_to_top(t_stack **stack_a, int target_value)
{
	int		stack_size;
	int		rotation_steps;
	t_stack	*current_node;

	stack_size = get_stack_size(*stack_a);
	current_node = *stack_a;
	rotation_steps = 0;
	while (current_node->next)
	{
		if (current_node->value == target_value)
			break ;
		rotation_steps++;
		current_node = current_node->next;
	}
	if (rotation_steps < stack_size / 2)
		while (rotation_steps--)
			ra(stack_a);
	else
		while (rotation_steps++ < stack_size)
			rra(stack_a);
}

void	restore_stack_a_from_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	target_value;

	while (*stack_b)
	{
		target_value = find_closest_higher(stack_a, (*stack_b)->value);
		align_to_top(stack_a, target_value);
		pa(stack_a, stack_b);
	}
}
