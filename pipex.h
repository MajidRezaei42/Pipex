/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:41:15 by arezaei           #+#    #+#             */
/*   Updated: 2025/09/24 11:41:16 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* INCLUDING LIBRARIES-------------- */
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
/* library required for perror */
# include <stdio.h>
/* library required for open, close... */
# include <fcntl.h>
/* library required for wait() */
# include <sys/wait.h>
# include <unistd.h>

/* DEFINING STRUCT------------------ */
typedef struct  s_pipex
{
    char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	int		pfd[2];
	pid_t	pid1;
	pid_t	pid2;
} t_pipex;

/* PROTOTYPES------------------------*/
char	*find_cmd_path(char **envp, char *cmd);
void	free_data(t_pipex *data);
void	exit_error(*msg, t_pipex *data);






#endif
