/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:32:37 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/20 14:25:42 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Definition of operators
// Swap "sa" "sb" "ss"
//Possibility of just using the first function to implement the operation

static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next) // Check if the stack has less than two nodes
		return ;
	first = *head; //Define first and second nodes
	second = (*head)->next;
	first->next = second->next; //Relink first node to point to the third one
	if (second->next) //If there is a third node its 'prev' pointer
		second->next->prev = first; //is updated to point back to the first node
	second->next = first; //Relink second node
	second->prev = first->prev; //Which is NULL for being the head
	first->prev = second; //Update second node
	*head = second; //Update head to point to the new top of the stack
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sa\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}

//Push operations "pa" "pb"

