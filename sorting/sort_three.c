/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:24:39 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/20 14:47:48 by jnajul           ###   ########.fr       */
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
