/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:40:19 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/23 12:40:20 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts an integer to a string representation.
// Allocates memory for the string and returns a pointer to it.Failure -> NULL
// The string representation includes a negative sign for negative integers.
// Hhandles the special case of INT_MIN (-2147483648) separately.
// Calculates the length of the number by repeatedly dividing it by 10.
// It uses a temporary variable to avoid modifying the original number.
// Uses a sign variable to determine if the number is negative.
// Allocates enough space for the string, including the null terminator.
// Fills the string from the end to the beginning, placing digits.
// in the correct order. It handles negative numbers by placing a '-' sign.

static	int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*ft_fillstr(char *str, int n, int len, int sign)
{
	str[len] = '\0';
	if (sign == -1)
	{
		str[0] = '-';
		n = -n;
	}
	while (n)
	{
		str[--len] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = 1;
	len = ft_intlen(n);
	if (n < 0)
		sign = -1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_fillstr(str, n, len, sign);
	return (str);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		test_values[] = {0, 123, -123, INT_MIN, INT_MAX, -1, 1};
	size_t	num_tests = sizeof(test_values) / sizeof(test_values[0]);
	char	*result;

	for (size_t i = 0; i < num_tests; i++)
	{
		result = ft_itoa(test_values[i]);
		if (result)
		{
			printf("ft_itoa(%d) = \"%s\"\n", test_values[i], result);
			free(result); // Don't forget to free the allocated memory
		}
		else
		{
			printf("ft_itoa(%d) failed to allocate memory.\n", test_values[i]);
		}
	}
	return (0);
}
*/
