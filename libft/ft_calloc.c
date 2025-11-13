/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:18:08 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/17 12:18:10 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tot;

	tot = nmemb * size;
	if (nmemb != 0 && ((tot / nmemb) != size))
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(tot);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, tot);
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>  // for memcmp

void print_bytes(const void *ptr, size_t n) {
	const unsigned char *bytes = (const unsigned char *)ptr;
	for (size_t i = 0; i < n; i++) {
		printf("%02x ", bytes[i]);
	}
	printf("\n");
}

int main(void) {
	size_t n = 10;
	size_t size = sizeof(int);

	// Test 1: Normal allocation
	void *std = calloc(n, size);
	void *mine = ft_calloc(n, size);

	printf("Standard calloc: ");
	print_bytes(std, n * size);

	printf("Your ft_calloc:  ");
	print_bytes(mine, n * size);

	if (memcmp(std, mine, n * size) == 0)
		printf("✅ Memory is correctly zero-initialized\n");
	else
		printf("❌ Memory differs!\n");

	free(std);
	free(mine);

	// Test 2: Zero-size allocation
	void *z1 = ft_calloc(0, 100);
	void *z2 = ft_calloc(100, 0);

	if (z1 && z2)
		printf("✅ Zero-size allocations returned non-NULL (safe to free)\n");

	free(z1);
	free(z2);

	// Test 3: Overflow (try SIZE_MAX / 2)
	// This may vary based on system; this check should return NULL
	size_t big = (size_t)-1;
	void *overflow = ft_calloc(big, 2);
	if (overflow == NULL)
		printf("✅ Overflow correctly detected and NULL returned\n");
	else
		printf("❌ Overflow test failed\n");

	free(overflow);
	return 0;
}
*/
