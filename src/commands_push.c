/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:30:17 by atbicer           #+#    #+#             */
/*   Updated: 2025/05/11 02:04:34 by atbicer          ###   ########.fr       */
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

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	// Remove node from source stack
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	// Add node to destination stack
	push_node->prev = NULL;
	push_node->next = *dst;
	if (*dst)
		(*dst)->prev = push_node;
	*dst = push_node;
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
