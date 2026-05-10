#include "push_swap.h"

t_node	*create_new(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	stack_add_node(t_sort_stack *stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	if (stack->size == 0)
	{
		stack->top = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last = stack->top->prev; 
		new_node->next = stack->top;
		new_node->prev = last;
		last->next = new_node;
		stack->top->prev = new_node;
	}
	stack->size++;
}

void	stack_push_top(t_sort_stack *stack, t_node *node)
{
	t_node	*last;
	
	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		last = stack->top->prev;
		last->next = node;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

t_node	*stack_pop_top(t_sort_stack *stack)
{
	t_node	*new;
	t_node	*last;
	
	if (!stack || stack->size == 0)
		return (NULL);
	new = stack->top;
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		last = new->prev;
		stack->top = new->next;
		stack->top->prev = last;
		last->next = stack->top;
	}
	new->next = NULL;
	new->prev = NULL;
	stack->size--;
	return (new);
}

void	free_stack(t_sort_stack *stack)
{
	t_node	*current;
	t_node	*next_node;
	int		i;

	if (!stack || stack->size == 0)
		return ;
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		i++;
	}
	stack->top = NULL;
	stack->size = 0;
}
