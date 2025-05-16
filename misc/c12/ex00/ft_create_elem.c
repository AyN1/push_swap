/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:26:58 by atbicer           #+#    #+#             */
/*   Updated: 2025/05/16 09:29:26 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_list *ft_create_elem(void *data)
{
	t_list *new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}
