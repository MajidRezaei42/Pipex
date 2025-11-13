/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:12:15 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/23 14:12:16 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Applies the function f to each character of the
//string s, passing its index as the first argument
//and the character itself as the second. A new
//New string is created to store the results after applications of f.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;
	size_t			len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
// Example function to be passed to ft_strmapi
char example_function(unsigned int index, char c)
{
    // For testing, let's convert every character to uppercase.
    return (char)((c >= 'a' && c <= 'z') ? c - 32 : c);
	index = index % 10; // Just an example of using the index;
}

int main(void)
{
    char *original = "hello world!";
    char *modified;

    modified = ft_strmapi(original, example_function);
    if (!modified)
    {
        printf("Memory allocation failed or invalid input.\n");
        return (1);
    }

    printf("Original: %s\n", original);
    printf("Modified: %s\n", modified);

    free(modified);
    return (0);
}
*/
