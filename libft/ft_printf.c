/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:29:56 by arezaei           #+#    #+#             */
/*   Updated: 2025/07/02 09:29:57 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start (args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			count += ft_format(args, *(format + 1));
			format += 2;
		}
		else
		{
			write (1, format, 1);
			format ++;
			count ++;
		}
	}
	va_end(args);
	return (count);
}
