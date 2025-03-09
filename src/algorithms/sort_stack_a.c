#include "../../include/push_swap.h"

static int	is_sorted(t_stack **stack_a)
{
	t_stack	*current_node;
	int		unsorted_count;

	current_node = *stack_a;
	unsorted_count = 0;
	while (current_node->next)
	{
		if (current_node->value > current_node->next->value)
			unsorted_count++;
		if (unsorted_count > 1)
			return (0);
		current_node = current_node->next;
	}
	if (unsorted_count == 1 && current_node->value > (*stack_a)->value)
		return (0);
	return (1);
}

static void	move_min_to_top(t_stack **stack_a)
{
	int		stack_size;
	int		steps_to_min;
	t_stack	*current_node;

	stack_size = get_stack_size(*stack_a);
	current_node = *stack_a;
	steps_to_min = 0;
	while (current_node)
	{
		steps_to_min++;
		if (current_node->next && \
		current_node->value > current_node->next->value)
			break ;
		current_node = current_node->next;
	}
	if (steps_to_min <= stack_size / 2)
		while (steps_to_min--)
			ra(stack_a);
	else
		while (steps_to_min++ < stack_size)
			rra(stack_a);
}

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	if (stack_size <= 1)
		return ;
	if (stack_size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return ;
	}
	while (!is_sorted(stack_a))
	{
		if (stack_size == 3)
		{
			sort_three_elements(stack_a);
			break ;
		}
		find_and_push_optimal_to_stack_b(stack_a, stack_b);
		stack_size--;
	}
	restore_stack_a_from_stack_b(stack_a, stack_b);
	move_min_to_top(stack_a);
}
