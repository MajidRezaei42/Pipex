/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:51:40 by arezaei           #+#    #+#             */
/*   Updated: 2025/07/25 15:51:42 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long	n;
	int				count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	n = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex_long(n, 0);
	return (count);
}
