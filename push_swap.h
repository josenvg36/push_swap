/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:29:24 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/21 17:20:43 by jnajul           ###   ########.fr       */
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


// swap.c
static void		swap(t_stack_node **head);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

// push.c
static void		push(t_stack_node **dst, t_stack_node **src);
void			push_a(t_stack_node **a, t_stack_node **b, bool print);
void			push_b(t_stack_node **a, t_stack_node **b, bool print);

// rotate.c
static void		rotate(t_stack_node **stack);
void			rotate_a(t_stack_node **a, bool print);
void			rotate_b(t_stack_node **b, bool print);
void			rotate_both(t_stack_node **a, t_stack_node **b, bool print);

// reverse_rotate.c
static void		reverse_rotate(t_stack_node **stack);
void			rr_a(t_stack_node **a, bool print);
void			rr_b(t_stack_node **b, bool print);
void			rr_both(t_stack_node **a, t_stack_node **b, bool print);

// utils.c
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);	
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
// sort_three.c
void			sort_three(t_stack_node **stack);
static void		move_a_to_b(t_stack_node **a, t_stack_node **b);
static void		move_b_to_a(t_stack_node **a, t_stack_node **b);
static void		min_on_top(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

// initialization.c
static long		ft_atol(const char *s);
static void		append_node(t_stack_node **stack, int n);
void			init_stack_a(t_stack_node **a, char **argv);
t_stack_node	*get_cheapest_node(t_stack_node *stack);
void			prep(t_stack_node **stack, t_stack_node *top_node, char name);

// error_handling.c
int				error_syntax(char *str);
int				if_duplicate(t_stack_node *stack, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **stack);

//init_nodes (init_a.c && init_b.c)
void			cursor(t_stack_node *stack);
static void		set_target_a(t_stack_node *a, t_stack_node *b);
static void		cost_analysis_a(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			init_a(t_stack_node *a, t_stack_node *b);
static void		set_target_b(t_stack_node *a, t_stack_node *b);
void			init_b(t_stack_node *a, t_stack_node *b);


#endif