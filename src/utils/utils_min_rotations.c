#include "../../include/push_swap.h"

static int	find_target_position_in_stack_a(t_stack **stack_a, int value)
{
	t_stack	*current_node;
	int		target_value;

	current_node = *stack_a;
	if (!current_node)
		return (value);
	target_value = find_min_value(*stack_a);
	if (value < target_value || value > find_max_value(*stack_a))
	{
		while (current_node)
		{
			if (current_node->value > target_value)
				target_value = current_node->value;
			current_node = current_node->next;
		}
		return (target_value);
	}
	current_node = *stack_a;
	while (current_node)
	{
		if (current_node->value < value && current_node->value > target_value)
			target_value = current_node->value;
		current_node = current_node->next;
	}
	return (target_value);
}

static void	calculate_rotation_stack_a(t_stack **stack_a, t_move *curr_move)
{
	int		stack_size;
	int		distance;
	t_stack	*current_node;

	stack_size = get_stack_size(*stack_a);
	current_node = *stack_a;
	distance = 0;
	while (current_node->next)
	{
		if (current_node->value == curr_move->value)
			break ;
		distance++;
		current_node = current_node->next;
	}
	if (distance <= stack_size / 2)
		curr_move->ra = distance;
	else
		curr_move->rra = stack_size - distance;
}

static void	calculate_rotation_stack_b(t_stack **stack_b, t_move *curr_move)
{
	int		stack_size;
	int		distance;
	int		target_value;
	t_stack	*current_node;

	stack_size = get_stack_size(*stack_b);
	current_node = *stack_b;
	distance = 0;
	target_value = find_target_position_in_stack_a(stack_b, curr_move->value);
	while (current_node)
	{
		if (current_node->value == target_value)
			break ;
		distance++;
		current_node = current_node->next;
	}
	if (distance <= stack_size / 2)
		curr_move->rb = distance;
	else
		curr_move->rrb = stack_size - distance;
}

void	calculate_total_moves(
	t_stack **stack_a, t_stack **stack_b, t_move *curr_move)
{
	calculate_rotation_stack_a(stack_a, curr_move);
	calculate_rotation_stack_b(stack_b, curr_move);
}
