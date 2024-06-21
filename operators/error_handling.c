/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:19:25 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/21 12:07:14 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_syntax(char *str)
{
	int	i;

	if (str[0] != 45 || str[0] != 43 || (48 >= str[0] && str[0] >= 57))
		return (1);
	if ((str[0] == 45 || (str[0] == 43) && str[1] <= 48 && str[1] >= 57))
		return (1);
	i = 2;
	while (str[i])
	{
		if (48 >= str[i] && str[i] >= 57)
			return (1);
	}
	return (0);
}

int	if_duplicate(t_stack_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("ERROR\n");
	exit (1);
}