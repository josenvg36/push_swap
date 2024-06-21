/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:24:39 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/21 17:19:56 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;
	t_stack_node	*biggest_num;

	if (!stack || !(*stack) ||!(*stack)->next || (*stack)->next->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	biggest_num = first;
	if (second->nbr > biggest_num->nbr)
		biggest_num = second;
	if (third->nbr > biggest_num)
		biggest_num = third;
	if (biggest_num == first)
		rotate_a(stack, false);
	else if (biggest_num == second)
		rr_a(stack, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, false);
	else if (!(cheapest_node->above_median) 
			&& !(cheapest_node->target->above_median))
		reverse_rotate(a, b, false);
	prep(a, cheapest_node, 'a');
	prep(b, cheapest_node->target, 'b');
	push_b(b, a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep(a, (*b)->target, 'a');
	push_a(a, b, false);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			rotate_a(a, false);
		else
			rr_a(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		push_b(a, b, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		push_b(a, b, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b); 
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	cursor(*a);
	min_on_top(a);
}

