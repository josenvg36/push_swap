/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:32:37 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/19 18:44:11 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Definition of operators
// Swap "sa" "sb" "ss"
//Possibility of just using the first function to implement the operation

void	swap(t_stack_node **head)
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

static void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*push_node;

	if (!*b)
		return ;
	push_node = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	if (!*a)
	{
		*a = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *a;
		push_node->next->prev = push_node;
		*a = push_node;
	}
}

//Rotate operations

void	rotate(t_stack *a)
{
	t_node	*first;
	t_node	*current;

	if (a->top)
	{
		first = a->top;
		a->top = a->top->next;
		current = a->top;
		while (current->next)
			current = current->next;
		current->next = first;
		first->next = NULL;
	}
}

void	reverse_rotate(t_stack *a)
{
	t_node	*last;
	t_node	*current;

	current = a->top;
	last = NULL;
	while (current->next)
	{
		last = current;
		current = current->next;
	}
	if (last)
	{
		last->next = NULL;
		current->next = a->top;
		a->top = current;
	}
}
