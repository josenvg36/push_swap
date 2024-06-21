/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:59:17 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/20 14:25:24 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node; // Pointer to the node to be pushed

	if (!*src) // If the source stack is empty, nothing to push
		return ;
	push_node = *src; // Assign the top node of the source top to the  push_node
	*src = (*src)->next; // Move the source stack top to the next node
	if (*src) // If the new top node of the source stack exists
		(*src)->prev = NULL; // Set its prev pointer to NULL, making it the new head
	push_node->next = *dst; // Point the node to be pushed to the current top of the dst stack
	push_node->prev = NULL; // Detach the push_node's prev pointer
	if (*dst) // If dst stack is not empty
		(*dst)->prev = push_node; // Set the current top node's prev pointer to the push_node
	*dst = push_node;  // Set the top of the dst stack to the push_node
}

void	push_a(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	push_b(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}




