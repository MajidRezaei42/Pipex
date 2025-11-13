/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:39:43 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/13 19:39:45 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}
/*
#include <stdio.h>

int	ft_toupper(int c);

int main(void)
{
	printf("%c -> %c\n", 'a', ft_toupper('a'));  // A
	printf("%c -> %c\n", 'z', ft_toupper('z'));  // Z
	printf("%c -> %c\n", 'A', ft_toupper('A'));  // A (unchanged)
	printf("%c -> %c\n", '1', ft_toupper('1'));  // 1 (unchanged)
	return 0;
}
*/
