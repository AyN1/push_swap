/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:21:51 by atbicer           #+#    #+#             */
/*   Updated: 2025/05/23 10:10:13 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
/*


function	add_node_bottom(stack, value):
	new_node = malloc(sizeof(t_stack_node))
	if new_node is NULL:
		return

	new_node->value = value
	new_node->next = NULL

	if *stack is NULL:
		new_node->prev = NULL
		*stack = new_node
		return


	last = *stack
	while last->next is not NULL:
		last = last->next

	last->next = new_node
	new_node->prev = last


function	contains_duplicate(stack, value):
	current = stack
	while current is not NULL:
		if current->value == value:
			return true
		current = current->next
	return false


function	stack_len(stack):
	count = 0
	current = stack
	while current is not NULL:
		count++
		current = current->next
	return count


function	stack_sorted(stack):
	if stack is NULL:
		return true

	current = stack
	while current->next is not NULL:
		if current->value > current->next->value:
			return false
		current = current->next
	return true


function	free_stack(stack):
	while stack is not NULL:
		temp = stack
		stack = stack->next
		free(temp)
		*/
