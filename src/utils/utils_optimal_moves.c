#include "../include/push_swap.h"

static void	execute_optimal_moves(
	t_stack **stack_a, t_stack **stack_b, t_move *best_move)
{
	while (best_move->ra && best_move->rb && \
			best_move->ra-- && best_move->rb--)
		rr(stack_a, stack_b);
	while (best_move->rra && best_move->rrb && \
			best_move->rra-- && best_move->rrb--)
		rrr(stack_a, stack_b);
	while (best_move->ra && best_move->ra--)
		ra(stack_a);
	while (best_move->rb && best_move->rb--)
		rb(stack_b);
	while (best_move->rra && best_move->rra--)
		rra(stack_a);
	while (best_move->rrb && best_move->rrb--)
		rrb(stack_b);
	pb(stack_a, stack_b);
}

static int	calc_move(t_move *move_steps)
{
	int	move_count;

	if (move_steps->ra > move_steps->rb)
		move_count = move_steps->ra;
	else
		move_count = move_steps->rb;
	if (move_steps->rra > move_steps->rrb)
		move_count += move_steps->rra;
	else
		move_count += move_steps->rrb;
	return (move_count);
}

void	find_and_push_optimal_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_node;
	t_move	curr_move;
	t_move	best_move;

	current_node = *stack_a;
	best_move.ra = -1;
	while (current_node)
	{
		curr_move.value = current_node->value;
		curr_move.ra = 0;
		curr_move.rb = 0;
		curr_move.rra = 0;
		curr_move.rrb = 0;
		calculate_total_moves(stack_a, stack_b, &curr_move);
		if (best_move.ra == -1 || calc_move(&curr_move) < calc_move(&best_move))
		{
			best_move.value = curr_move.value;
			best_move.ra = curr_move.ra;
			best_move.rb = curr_move.rb;
			best_move.rra = curr_move.rra;
			best_move.rrb = curr_move.rrb;
		}
		current_node = current_node->next;
	}
	execute_optimal_moves(stack_a, stack_b, &best_move);
}
