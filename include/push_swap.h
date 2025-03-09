#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_move
{
	int	value;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_move;

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b);
void	sort_three_elements(t_stack **stack_a);

void	free_stack_and_exit(t_stack *stack, int error_flag);
void	populate_stack(t_stack **stack, char **input_strings);
void	find_and_push_optimal_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void	restore_stack_a_from_stack_b(t_stack **stack_a, t_stack **stack_b);
void	calculate_total_moves(
			t_stack **stack_a, t_stack **stack_b, t_move *curr_move);

int		get_stack_size(t_stack *stack);
int		find_min_value(t_stack *stack_a);
int		find_max_value(t_stack *stack_a);

t_stack	*get_last_node(t_stack *stack);

#endif
