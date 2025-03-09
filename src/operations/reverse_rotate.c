#include "../../include/push_swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return (0);
	last_node = get_last_node(*stack);
	second_last_node = *stack;
	while (second_last_node)
	{
		if (second_last_node->next == last_node)
			second_last_node->next = NULL;
		second_last_node = second_last_node->next;
	}
	last_node->next = *stack;
	*stack = last_node;
	return (1);
}

void	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a))
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b))
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (reverse_rotate(stack_a) | reverse_rotate(stack_b))
		ft_printf("rrr\n");
}
