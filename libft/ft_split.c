/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:21:14 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/19 11:21:15 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*** ft_split - Splits a string into an array of strings based on a delimiter.
** @s: The string to split.
** @c: The delimiter character.
*** Returns: An array of strings (char **) where each string is a word from the
** string, or NULL if memory allocation fails.
** The last element of the array is NULL to indicate the end of the array.*/
static int	ft_word_count(char const *s, int c)
{
	int	count;
	int	in_word;

	if (!s)
		return (0);
	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static	char	**ft_substr_fail(char **splitted, int i_word)
{
	while (--i_word >= 0)
		free (splitted[i_word]);
	free (splitted);
	return (NULL);
}

static char	*ft_get_word(const char *s, char c, int *i)
{
	int	start;
	int	len;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	len = 0;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		len++;
	}
	return (ft_substr(s, start, len));
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		i_word;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	splitted = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	i_word = 0;
	while (i_word < word_count)
	{
		splitted[i_word] = ft_get_word(s, c, &i);
		if (!splitted[i_word])
			return (ft_substr_fail (splitted, i_word));
		i_word++;
	}
	splitted[i_word] = NULL;
	return (splitted);
}
/*
#include <stdio.h>
// A simple helper to print the result
void print_split(char **split)
{
	int i = 0;
	while (split[i])
	{
		printf("split[%d] = \"%s\"\n", i, split[i]);
		i++;
	}
}

int main(void)
{
	char *str1 = "hello world this is 42";
	char *str2 = "   spaced   out   ";
	char *str3 = "nospace";
	char *str4 = "";
	char **result;

	// Test 1
	printf("Test 1:\n");
	result = ft_split(str1, ' ');
	if (result)
	{
		print_split(result);
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}

	// Test 2
	printf("\nTest 2:\n");
	result = ft_split(str2, ' ');
	if (result)
	{
		print_split(result);
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}

	// Test 3
	printf("\nTest 3:\n");
	result = ft_split(str3, ' ');
	if (result)
	{
		print_split(result);
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}

	// Test 4
	printf("\nTest 4:\n");
	result = ft_split(str4, ' ');
	if (result)
	{
		print_split(result);
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}

	return 0;
}
*/