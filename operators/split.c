/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnajul <jnajul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:33:43 by jnajul            #+#    #+#             */
/*   Updated: 2024/06/23 22:04:05 by jnajul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static int count_words(char *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char *get_next_word(char **s, char c)
{
	char *word;
	char *start;
	char *end;
	int i;

	i = 0;
	start = *s;
	while (**s == c)
		(*s)++;
	start = *s;
	while (**s != c && **s)
		(*s)++;
	end = *s;
	word = malloc(sizeof(char) * (size_t)(end - start + 1));
	if (!word)
		exit (1);
	while (start < end)
		word[i++] = *start++;
	word[i] = '\0';
	return (word);
}

char **split(char *s, char c)
{
	int words_count;
	char **result_array;
	int i;

	i = 0;
	words_count = count_words(s, c);
	if (!count_words)
		exit (1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		exit (1);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				exit (1);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(&s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}