#include "../../include/push_swap.h"

void	sort_three_elements(t_stack **stack_a)
{
	if ((*stack_a)->next->value > (*stack_a)->value && \
	(*stack_a)->next->value > (*stack_a)->next->next->value)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value && \
	(*stack_a)->value > (*stack_a)->next->next->value)
		ra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
