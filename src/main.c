/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:14:53 by atbicer           #+#    #+#             */
/*   Updated: 2025/05/03 15:06:47 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char **split(char *s, char c);

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	else
		argv++; // I prefer to skip the first argument directly from here as my ft_split will skip too so I have same output in both situation with 2 args or more.


	// ft_printf("debug: ");
	// for (int i = 0; argv[i]; i++)
	// 	ft_printf("[%s]", argv[i]);

	// init stack
	(void)b; // to remove
	stack_init(&a, argv); // no need to send argv+1 as the first arg is already skipped.
	// if (!stack_sorted(a))
	// {
	// 	if (stack_len(a) == 2)
	// 		sa(&a, false);
	// 	else if (stack_len(a) == 3)
	// 		// tiny sort function
	// 		sort_three(&a);
	// 	else
	// 	// turk algo
	// 	 sort_stacks(&a, &b);
	// }
	// free stack
	
	// Debug, print A stack	
	for (; a; a = a->next)
   	 ft_printf("[%d] ", a->nbr);
	
	free_stack(&a);

}
