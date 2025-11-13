/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:45:49 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/10 12:45:50 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>

int main (void)
{
	char ch;
	
	ch = '0';
	if (ft_isdigit(ch))
		printf("'%c' is a digit", ch);
	else
		printf("'%c' is not a digit", ch);
}
*/
