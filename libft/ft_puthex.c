/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:37:03 by arezaei           #+#    #+#             */
/*   Updated: 2025/07/25 12:37:04 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	int		count;
	char	c;
	char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	c = hex_digits[n % 16];
	count += ft_putchar(c);
	return (count);
}

int	ft_puthex_long(unsigned long n, int uppercase)
{
	int		count;
	char	c;
	char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_long(n / 16, uppercase);
	c = hex_digits[n % 16];
	count += ft_putchar(c);
	return (count);
}
