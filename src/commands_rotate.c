/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:21:44 by atbicer           #+#    #+#             */
/*   Updated: 2025/05/11 01:46:33 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
    // to do
}

void	ra(t_stack_node **a, bool checker)
{
	rotate(a);
	if (checker)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (checker)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (checker)
		ft_printf("rr\n");
}
