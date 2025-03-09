#include "../../include/push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return (0);
	last_node = get_last_node(*stack);
	first_node = *stack;
	*stack = (*stack)->next;
	first_node->next = NULL;
	last_node->next = first_node;
	return (1);
}

void	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	if (rotate(stack_b))
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (rotate(stack_a) | rotate(stack_b))
		ft_printf("rr\n");
}
