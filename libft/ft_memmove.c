/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:31:17 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/12 12:31:19 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src_ptr;
	unsigned char		*dest_ptr;

	src_ptr = (const unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	if (src_ptr == dest_ptr || n == 0)
		return (dest);
	if (src_ptr > dest_ptr)
	{
		i = 0;
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			dest_ptr[i] = src_ptr[i];
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void *ft_memmove(void *dest, const void *src, size_t n);

// Allocate and initialize buffer
void fill_buffer(char *buf, size_t size)
{
	for (size_t i = 0; i < size; i++)
		buf[i] = (char)(i % 256);
}

int main(void)
{
	const size_t size = 100000000;  // 100 MB
	const int iterations = 50;

	char *src1 = malloc(size);
	char *dest1 = malloc(size);
	char *src2 = malloc(size);
	char *dest2 = malloc(size);

	if (!src1 || !dest1 || !src2 || !dest2) {
		perror("malloc");
		return 1;
	}

	fill_buffer(src1, size);
	memcpy(src2, src1, size);  // Make identical copy for fair test

	// Benchmark standard memmove
	clock_t start = clock();
	for (int i = 0; i < iterations; i++)
		memmove(dest1, src1, size);
	clock_t end = clock();
	double std_time = (double)(end - start) / CLOCKS_PER_SEC;

	// Benchmark your ft_memmove
	start = clock();
	for (int i = 0; i < iterations; i++)
		ft_memmove(dest2, src2, size);
	end = clock();
	double ft_time = (double)(end - start) / CLOCKS_PER_SEC;

	// Print results
	printf("Standard memmove time: %.3f sec\n", std_time);
	printf("Your ft_memmove time:  %.3f sec\n", ft_time);

	// Optional: check correctness
	if (memcmp(dest1, dest2, size) == 0)
		printf("✅ Buffers match: ft_memmove is correct\n");
	else
		printf("❌ Buffers differ: bug in ft_memmove\n");

	free(src1); free(dest1);
	free(src2); free(dest2);

	return 0;
}
*/
