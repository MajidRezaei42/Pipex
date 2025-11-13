/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:42:23 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/17 13:42:24 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	len_str;
	size_t	maxlen;

	if (!s)
		return (NULL);
	i = 0;
	len_str = ft_strlen(s);
	maxlen = len_str - start;
	if (start >= len_str)
		return ((char *)ft_calloc(1, 1));
	if (len > maxlen)
		len = maxlen;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr [i] = s[(size_t)start + i];
		i++;
	}
	substr [len] = '\0';
	return (substr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "THIS IS WHAT I WANT TO BE!";
	char	*substr;
	int		start;
	int		len;
	
	start = 5;
	len = 10;
	
	substr = ft_substr(str, start, len);
	printf("the created sub string is '%s'\n", substr);
	free (substr);
}
*/
