/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:04:16 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/18 11:04:17 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = malloc((end - start) + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[(end - start)] = '\0';
	return (trimmed);
}
/*
#include <stdio.h>
int main(void)
{
    char *result;

    result = ft_strtrim("  \n\tHello World\t \n", " \n\t");
    printf("Test 1: '%s'\n", result);
    free(result);

    result = ft_strtrim("abHelloabc", "abc");
    printf("Test 2: '%s'\n", result);
    free(result);

    result = ft_strtrim("Hello", "");
    printf("Test 3: '%s'\n", result);
    free(result);

    result = ft_strtrim("aaaa", "a");
    printf("Test 4: '%s'\n", result);
    free(result);

    result = ft_strtrim("", "abc");
    printf("Test 5: '%s'\n", result);
    free(result);

    result = ft_strtrim(NULL, "abc");
    printf("Test 6: %s\n", result ? result : "NULL");

    result = ft_strtrim("Hello", NULL);
    printf("Test 7: %s\n", result ? result : "NULL");

    return 0;
}
*/
