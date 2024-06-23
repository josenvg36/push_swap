/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:22:58 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/23 21:31:43 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MIN;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr < b->nbr && current_a->nbr > best_match_index)
			{
				best_match_index = current_a;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MIN)
			b->target = find_max(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	init_b(t_stack_node *a, t_stack_node *b)
{
	cursor(a);
	cursor(b);
	set_target_b(a, b);
}

static void	rotate_both((t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (a != cheapest_node && b != cheapest_node)
	{
		rotate_both(a, b, true);
	}
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both((t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (a != cheapest_node && b != cheapest_node)
	{
		rr_both(a, b, true);
	}
	current_index(*a);
	current_index(*b);
}