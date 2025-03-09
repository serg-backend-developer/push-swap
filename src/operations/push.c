#include "../../include/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*moved_node;

	if (!*stack_b)
		return ;
	moved_node = *stack_b;
	*stack_b = (*stack_b)->next;
	moved_node->next = *stack_a;
	*stack_a = moved_node;
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*moved_node;

	if (!*stack_a)
		return ;
	moved_node = *stack_a;
	*stack_a = (*stack_a)->next;
	moved_node->next = *stack_b;
	*stack_b = moved_node;
	ft_printf("pb\n");
}
