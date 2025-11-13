/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:48:04 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/13 20:48:05 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	strlen;

	strlen = 0;
	while (s[strlen])
		strlen++;
	i = strlen;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "hghgxahsgdahxz";
	char	ch = 'x';
	int		loc;
	
	int strlen = 0;
	while (str[strlen])
		strlen++;
	loc = ft_strrchr(str, ch) - str;
	if (loc < strlen + 1)
		printf("'%c' found last time in '%s' at the '%d' location", ch, str,
			loc + 1 );
	else
		printf("'%c' not found in '%s'", ch, str);
}
*/
