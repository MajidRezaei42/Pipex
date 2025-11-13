/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:03:30 by arezaei           #+#    #+#             */
/*   Updated: 2025/07/21 12:03:31 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list args, char specifier)
{
	if (specifier == 'c')
		return (ft_putchar (va_arg (args, int)));
	else if (specifier == 's')
		return (ft_putstr (va_arg (args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr (va_arg (args, int)));
	else if (specifier == 'u')
		return (ft_put_unsigned (va_arg (args, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthex (va_arg (args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_puthex (va_arg (args, unsigned int), 1));
	else if (specifier == 'p')
		return (ft_putptr (va_arg (args, void *)));
	else if (specifier == '%')
		return (ft_putchar (specifier));
	return (0);
}
