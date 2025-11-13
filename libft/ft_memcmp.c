/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:20:09 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/16 11:20:11 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	s1_ptr = (const unsigned char *)s1;
	s2_ptr = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return ((int)(s1_ptr[i] - s2_ptr[i]));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char a[] = "Hello, world!";
	char b[] = "Hello, world!";
	char c[] = "Hello, Worle!"; // Note the 'e' instead of 'd'

	printf("Test 1 (a vs b): %d\n", ft_memcmp(a, b, sizeof(a)));  
	printf("Test 2 (a vs c): %d\n", ft_memcmp(a, c, sizeof(a)));   
	printf("Test 3 (first 5 bytes of a vs c): %d\n", ft_memcmp(a, c, 5));
	printf("Test 4 (empty compare): %d\n", ft_memcmp(a, c, 0));   
	// Bonus: show difference from standard memcmp
	printf("Standard memcmp (a vs c): %d\n", memcmp(a, c, sizeof(a)));

	return 0;
}
*/
