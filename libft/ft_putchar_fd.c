/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:31:11 by arezaei           #+#    #+#             */
/*   Updated: 2025/06/26 14:31:12 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*
#include <fcntl.h>    // for open
#include <unistd.h>   // for close

int main(void)
{
	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);

	ft_putchar_fd('A', fd);  // Writes 'A' to test.txt
	ft_putchar_fd('\n', fd); // Writes newline

	close(fd);
	return (0);
}
*/
