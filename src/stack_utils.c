/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:21:51 by atbicer           #+#    #+#             */
/*   Updated: 2025/05/11 01:27:44 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool    stack_sorted(t_stack_node *stack) // 32m
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

t_stack_node	*find_last(t_stack_node *stack) //Define a function that returns the pointer to the last node
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_min(t_stack_node *stack) //Define a function that searches a stack and returns the node with the smallest number
{
	long			min; //To store the smallest value so far
	t_stack_node	*min_node; //To store a pointer that points to the smallest number

	if (!stack)
		return (NULL);
	min = LONG_MAX; //Assign to the smallest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->nbr < min) //Check if the current node value is smaller than the smallest so far
		{
			min = stack->nbr; //If so, update the smallest number so far
			min_node = stack; //Set the pointer to point to the node with the smallest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	long			max; //To store the biggest value so far
	t_stack_node	*max_node; //To store a pointer that points to the biggest number

	if (!stack)
		return (NULL);
	max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->nbr > max) //Check if the current node value is smaller than the biggest so far
		{
			max = stack->nbr; //If so, update the biggest number so far
			max_node = stack; //Set the pointer to point to the node with the biggest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (max_node);
}
/*

// Add node to bottom of stack
function add_node_bottom(stack, value):
    new_node = malloc(sizeof(t_stack_node))
    if new_node is NULL:
        return

    new_node->value = value
    new_node->next = NULL

    if *stack is NULL:
        new_node->prev = NULL
        *stack = new_node
        return

    // Find last node
    last = *stack
    while last->next is not NULL:
        last = last->next

    last->next = new_node
    new_node->prev = last

// Check if stack contains duplicate value
function contains_duplicate(stack, value):
    current = stack
    while current is not NULL:
        if current->value == value:
            return true
        current = current->next
    return false

// Get stack length
function stack_len(stack):
    count = 0
    current = stack
    while current is not NULL:
        count++
        current = current->next
    return count

// Check if stack is sorted
function stack_sorted(stack):
    if stack is NULL:
        return true

    current = stack
    while current->next is not NULL:
        if current->value > current->next->value:
            return false
        current = current->next
    return true

// Free stack
function free_stack(stack):
    while stack is not NULL:
        temp = stack
        stack = stack->next
        free(temp)
		*/
