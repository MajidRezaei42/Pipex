/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:44:38 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/26 14:44:40 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}
/*
#include <fcntl.h>    // for open
#include <unistd.h>   // for close
#include <stdio.h>

int main(void)
{
	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	ft_putendl_fd("ABCVVFFCFGCFFGCF2121", fd);  // Writes 'A' to test.txt
	close(fd);
	return (0);
}
*/
