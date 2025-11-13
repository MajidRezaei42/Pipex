/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:49:41 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/13 19:49:42 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
/*
#include <stdio.h>

int	ft_tolower(int c);

int main(void)
{
	printf("%c -> %c\n", 'A', ft_tolower('A'));  // a
	printf("%c -> %c\n", 'Z', ft_tolower('Z'));  // z
	printf("%c -> %c\n", 'a', ft_tolower('a'));  // a (unchanged)
	printf("%c -> %c\n", '1', ft_tolower('1'));  // 1 (unchanged)
	return 0;
}
*/
