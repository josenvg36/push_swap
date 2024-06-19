/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:02:37 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/19 17:48:06 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_next_word(char *s, char c)
{
	static int	cursor;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

static int	count_words(char *s, char c)
{
	int		count;
	int		i;
	bool	inside_word;

	count = 0;
	i = 0;
	while (s[i])
	{
		inside_word = false;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			i++;
		}
	}
	return (count);
}

char	**split(char *s, char c)
{
	int		words_count;
	int		i;
	char	**result_array;

	i = 0;
	words_count = count_workds(s, c);
	if (!words_count)
		exit (1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}