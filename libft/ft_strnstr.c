/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:56:30 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/16 11:56:32 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	litlen;

	litlen = ft_strlen(little);
	if (!big && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && ((i + litlen) <= len))
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && big[i + j] == little[j])
				j++;
			if (j == litlen)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	*big = "THIS is nothing for finding Nothing!";
	const char	*little = "Nothing";
	char		*res;
	size_t		len;
	
	len = 40;
	
	res = ft_strnstr(big, little, len);
	printf("The Location of Found String is: %s\n", res);
}
*/
