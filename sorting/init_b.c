/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:22:58 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/21 16:26:17 by jnajul           ###   ########.fr       */
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