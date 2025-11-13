/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:41:33 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/12 11:41:34 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>   // for bzero, memcmp

// Declare your function
void ft_bzero(void *s, size_t n);

int main(void)
{
	size_t len = 10;
	char buf1[20] = "ABCDEFGHIJ";
	char buf2[20] = "ABCDEFGHIJ";

	// Apply standard bzero to buf1
	bzero(buf1 + 2, 5);

	// Apply your ft_bzero to buf2
	ft_bzero(buf2 + 2, 5);

	// Compare the two buffers
	if (memcmp(buf1, buf2, len) == 0)
		printf("✅ ft_bzero works correctly!\n");
	else
		printf("❌ ft_bzero differs from bzero.\n");

	// Print hex view (optional)
	printf("buf1: ");
	for (size_t i = 0; i < len; i++)
		printf("%02x ", (unsigned char)buf1[i]);
	printf("\nbuf2: ");
	for (size_t i = 0; i < len; i++)
		printf("%02x ", (unsigned char)buf2[i]);
	printf("\n");

	return 0;
}
*/
