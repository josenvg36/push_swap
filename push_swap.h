/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:29:24 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/19 16:25:40 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include <ctype.h>
# include "includes/libft/libft.h"
# include "includes/ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;


#endif