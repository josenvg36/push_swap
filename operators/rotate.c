/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:58:29 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/20 14:26:18 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next) // Stack is empty or only has one node
		return ;
	first = *stack;
	last = *stack;
	while (last->next) // Find the last node
		last = last->next;
	if (last->prev)
		last->prev->next = NULL; //Turn the second last pointer into the last one
	last->next = first; // Attaching the new first with the new second node
	first->prev = last; // Attaching new second node to the new head
	last->prev = NULL; // The last node becomes the new head, so prev is NULL
	*stack = last; // Update the stack head
}

void	rotate_a(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rotate_b(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rotate_both(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}