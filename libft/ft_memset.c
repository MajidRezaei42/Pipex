/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:36:22 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/12 11:36:24 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

// Declare your function
void *ft_memset(void *s, int c, size_t n);

int main(void)
{
    char buffer1[20] = "Hello, world!";
    char buffer2[20] = "Hello, world!";

    // Use standard memset
    memset(buffer1 + 7, '*', 5);

    // Use your function
    ft_memset(buffer2 + 7, '*', 5);

    // Print both results
    printf("Standard memset: %s\n", buffer1);
    printf("Your ft_memset:  %s\n", buffer2);

    // Compare results
    if (strcmp(buffer1, buffer2) == 0)
        printf("✅ ft_memset works correctly!\n");
    else
        printf("❌ There's a problem in your ft_memset.\n");

    return 0;
}
*/
