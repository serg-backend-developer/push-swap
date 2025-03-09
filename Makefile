NAME			= 	push_swap

PRINTF			= 	ft_printf/libftprintf.a
SRC				= 	src/
OBJ				= 	obj/
INCLUDE			= 	include/
GCC				= 	gcc
CFLAGS			=	-Wall -Werror -Wextra -I$(INCLUDE)
RM				=	rm -f

OPERATIONS		=	$(SRC)operations/push.c \
					$(SRC)operations/reverse_rotate.c \
					$(SRC)operations/rotate.c \
					$(SRC)operations/swap.c

UTILS			=	$(SRC)utils/utils_optimal_moves.c \
					$(SRC)utils/utils_restore_stack_a_from_stack_b.c \
					$(SRC)utils/utils_min_rotations.c \
					$(SRC)utils/utils_stack.c

ALGORITHMS		=	$(SRC)algorithms/sort_stack_a.c \
					$(SRC)algorithms/sort_three_elements.c

MAIN			=	$(SRC)main.c

SRCS 			= 	$(OPERATIONS) $(UTILS) $(ALGORITHMS) $(MAIN)
OBJS 			= 	$(patsubst $(SRC)%.c,$(OBJ)%.o,$(SRCS))

all: $(NAME)

$(PRINTF):
				@make -C ft_printf

$(NAME): $(OBJS) $(PRINTF)
				@$(GCC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(OBJ)%.o: $(SRC)%.c
				@mkdir -p $(@D)
				@$(GCC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) -r $(OBJ)
				@make clean -C ft_printf

fclean: clean
				@$(RM) $(NAME)
				@make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re
