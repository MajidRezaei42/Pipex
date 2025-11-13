/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:17:15 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/24 13:17:16 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to apply a function to each character of a string with its index
// Parameters:
// - s: The string to iterate over
// - f: The function to apply to each character, takes an index and a character
// Note: The function does not return anything, modifies the string in place

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* Example usage:
void my_function(unsigned int index, char *c) 
{
    *c = toupper(*c); // Convert character to uppercase
}

#include <stdio.h>
#include <ctype.h>
int main() 
{
     char str[] = "hello";
	 printf("Input: %s\n", str); // input: "HELLO"
     ft_striteri(str, my_function);
     printf("Output: %s\n", str); // Output: "HELLO"
     return 0;
}
 */
