#include "../../include/push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*first_node;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first_node = *stack_a;
	*stack_a = (*stack_a)->next;
	first_node->next = (*stack_a)->next;
	(*stack_a)->next = first_node;
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	t_stack	*first_node;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first_node = *stack_b;
	*stack_b = (*stack_b)->next;
	first_node->next = (*stack_b)->next;
	(*stack_b)->next = first_node;
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((!*stack_a || !(*stack_a)->next) && (!*stack_b || !(*stack_b)->next))
		return ;
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
