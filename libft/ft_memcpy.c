/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:01:40 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/12 12:01:42 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_ptr;
	unsigned char		*dest_ptr;
	size_t				i;

	if (!dest && !src && n > 0)
		return (NULL);
	i = 0;
	src_ptr = (const unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>  // for standard memcpy

void *ft_memcpy(void *dest, const void *src, size_t n);

int main(void)
{
	char std[20] = "Hello, World!";
	char custom[20] = "Hello, World!";

	// Apply standard memcpy
	memcpy(std + 7, "42!   ", 6);

	// Apply your ft_memcpy
	ft_memcpy(custom + 7, "42!   ", 6);

	// Compare results
	if (memcmp(std, custom, 20) == 0)
		printf("✅ ft_memcpy works correctly!\n");
	else
		printf("❌ ft_memcpy differs from memcpy.\n");

	// Print outputs
	printf("std:    %s\n", std);
	printf("custom: %s\n", custom);

	return 0;
}
*/
