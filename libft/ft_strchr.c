/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:06:46 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/13 20:06:47 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "hghgxahsgdahxz";
	char	ch = 'A';
	int		loc;
	
	int strlen = 0;
	while (str[strlen])
		strlen++;
	loc = ft_strchr(str, ch) - str;
	if (loc < strlen + 1)
		printf("'%c' found in '%s' at the '%d' location", ch, str, loc + 1 );
	else
		printf("'%c' not found in '%s'", ch, str);
}
*/
