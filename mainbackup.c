/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:12:26 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/03 10:12:30 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* argv[0]== pipex */
/* argv[1]== file1 (input file) */
/* argv[2]== cmd1 */
/* argv[3]== cmd2 */
/* argv[4]== file2 (output file) */
/* the first argument cmd1[0] is the cmd function name */

char	*find_path_value(char **envp)
{
	int		i;
	char	*path_value;

	i = 0;
	path_value = NULL;
	while ((envp[i] != NULL))
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_value = envp[i] + 5;
			break ;
		}
		i ++;
	}
	return (path_value);
}

//cmd is the function name
char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**path_dirs;
	char	*temp_path;
	char	*full_path;
	char	*valid_path;

	path_dirs = NULL;
	path_dirs = ft_split(find_path_value(envp), ':');
	if (path_dirs == NULL)
		return (NULL);
	i = 0;
	valid_path = NULL;
	temp_path = NULL;
	full_path = NULL;
	while ((path_dirs[i] != NULL))
	{
		temp_path = ft_strjoin(path_dirs[i], "/");
		if (temp_path == NULL)
		{
			ft_free_array(path_dirs);
			return (NULL);
		}
		full_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (full_path == NULL)
		{
			ft_free_array(path_dirs);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			valid_path = full_path;
			break ;
		}
		else
			free(full_path);
		i++;
	}
	ft_free_array(path_dirs);
	return (valid_path);
}

/////////////////////////////////////////////////////////////
int	main(int argc, char **argv, char **envp)
{
	char	**cmd1;
	char	**cmd2;
	char	*valid_path;
	char	*valid_path2;
	int		pfd[2];
	pid_t	pid;
	pid_t	pid2;
	int		file1_fd;
	int		file2_fd;

	if (argc != 5)
		return (1);
	cmd1 = ft_split(argv[2], ' ');
	if (cmd1 == NULL)
		return (1);
	valid_path = find_path(cmd1[0], envp);
	if (valid_path == NULL)
	{
		perror(cmd1[0]);
		ft_free_array(cmd1);
		exit (127);
	}
	cmd2 = ft_split(argv[3], ' ');
	if (cmd2 == NULL)
	{
		free(valid_path);
		ft_free_array(cmd1);
		return (1);
	}
	valid_path2 = find_path(cmd2[0], envp);
	if (valid_path2 == NULL)
	{
		perror(cmd2[0]);
		free(valid_path);
		ft_free_array(cmd1);
		ft_free_array(cmd2);
		exit (127);
	}


//////////////////////////////////////////////////////
	if (pipe(pfd) == -1)
		return (1); // handle error
	pid = fork();
	if (pid == -1)
		return (1); // handle error
	if (pid == 0)
	{
		file1_fd = open(argv[1], O_RDONLY);
		if (file1_fd == -1)
		{
			perror(argv[1]);
			free(valid_path);
			free(valid_path2);
			ft_free_array(cmd1);
			ft_free_array(cmd2);
			exit(1);
		}

		dup2(file1_fd, 0);
		close(file1_fd);
		dup2(pfd[1], 1);
		close(pfd[1]);
		close(pfd[0]);
		execve(valid_path, cmd1, envp);
		perror(cmd1[0]);
		free(valid_path);
		ft_free_array(cmd1);
		free(valid_path2);
		ft_free_array(cmd2);
		exit(127);
	}
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			return (1); // handle error
		if (pid2 == 0)
		{
			file2_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (file2_fd == -1)
			{
				perror(argv[4]);
				free(valid_path);
				ft_free_array(cmd1);
				ft_free_array(cmd2);
				free(valid_path2);
				exit(1);
			}
			dup2(file2_fd, 1);
			close(file2_fd);
			dup2(pfd[0], 0);
			close(pfd[1]);
			close(pfd[0]);
			execve(valid_path2, cmd2, envp);
			perror(cmd2[0]);
			free(valid_path);
			ft_free_array(cmd1);
			free(valid_path2);
			ft_free_array(cmd2);
			exit(127);
		}
		else
		{
			close(pfd[1]);
			close(pfd[0]);
			wait(NULL);
			wait(NULL);
			ft_free_array(cmd1);
			ft_free_array(cmd2);
			free(valid_path);
			free(valid_path2);
		}
		
	}
}
