/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:38:33 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/13 10:38:34 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	*src;
	char		dst[20];
	size_t		size;
	size_t		res;
	
	size = 0;
	src = "123456789";
	printf("Source string is '%s'\n", src);
	res = ft_strlcpy(dst, src, size);
	if (size > 0)
		printf("Dest. string is '%s'\n", dst);
	else
		printf("Nothing is copied to the Dest. string, size = 0!\n");
	printf("ft_strlcpy output is '%ld'\n", res);
}
*/
