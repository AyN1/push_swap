/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:24:20 by atbicer           #+#    #+#             */
/*   Updated: 2025/05/16 10:34:37 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate(t_stack_node **stack) //Define a funtion that rotates a stack's bottom node, to the top
{
	t_stack_node	*last; //To store the pointer to the last node

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last = find_last(*stack);
	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last->prev = NULL; //Detach itself from the node before it
	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last->next->prev = last; //Update the current last node of the stack
}

void	rra(t_stack_node **a, bool checker) //Rotate the bottom of `a` to the top of the stack and print the instruction
{
	rev_rotate(a);
	if (checker)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool checker) //Rotate the bottom of `b` to the top of the stack and print the instruction
{
	rev_rotate(b);
	if (checker)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	rev_rotate(a);
	rev_rotate(b);
	if (checker)
		ft_printf("rrr\n");
}
