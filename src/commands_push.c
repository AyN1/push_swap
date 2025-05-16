/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:30:17 by atbicer           #+#    #+#             */
/*   Updated: 2025/05/16 10:34:49 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Push a node to the top from src to dest (beware if stack empty: null)

// pa

// pb

/*

// Push top node from src to dest
function	push(dest, src):
	if src is NULL:
		return

	temp = src
	src = src->next

	if src:
		src->prev = NULL

	if dest is NULL:
		dest = temp
		temp->next = NULL
		temp->prev = NULL
	else:
		temp->next = dest
		dest->prev = temp
		dest = temp
*/

static void	push(t_stack_node **dst, t_stack_node **src) //Define a function that pushes a top node, from one stack to another's top node
{
	t_stack_node	*push_node; //Used to store the pointer to the node to be pushed

	if (!*src) //The top node of a stack to be pushed
		return ;
	push_node = *src; //The top node to push is assigned to the `t_stack_node` variable
	*src = (*src)->next; //Move the pointer of the stack to the next node, which will become the next `top node` after the node before is "popped off"
	if (*src) //Check if the current node exists
		(*src)->prev = NULL; //Set the current node as the head of the stack
	push_node->prev = NULL; //Detach the node to push from its stack
	if (!*dst) //Check if the other stack is empty
	{
		*dst = push_node; //If it's empty, assign as the first node of that stack, the node we want pushed
		push_node->next = NULL; //Ensure it is also set as the last node, e.g. properly null terminate the stack
	}
	else //If the other stack we want to push to is not empty
	{
		push_node->next = *dst; //Assign the node to push, to the top of the current top node of the stack
		push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
		*dst = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
// Push on top of `b`, the top `a` and print the instruction
{
	push(a, b);
	if (checker)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
// Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
	if (checker)
		ft_printf("pb\n");
}
