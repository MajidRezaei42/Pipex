/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:23:43 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/18 10:23:45 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_str(char *dst, const char *src, size_t start)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	char	*str;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	str = malloc(lens1 + lens2 + 1);
	if (!str)
		return (NULL);
	ft_copy_str(str, s1, 0);
	ft_copy_str(str, s2, lens1);
	str[lens1 + lens2] = '\0';
	return (str);
}
/*
#include <stdio.h>    // For printf

int main(void)
{
    const char *s1 = "Hello, ";
    const char *s2 = "World!";
    char *result = ft_strjoin(s1, s2);

    if (result)
    {
        printf("Joined string: %s\n", result);
        free(result);  // Don't forget to free the allocated memory
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
