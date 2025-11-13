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


void	init_data(char **argv, char **envp, t_pipex *data)
{
	data->cmd1 = ft_split(argv[2], ' ');
	if (!data->cmd1)
		exit_error("malloc failed", data);
	data->cmd2 = ft_split(argv[3], ' ');
	if (!data->cmd2)
		exit_error("malloc failed", data);
	data->cmd1_path = find_path(data->cmd1[0], envp);
	if (!data->cmd1_path)
	{
		perror(data->cmd1[0]);
		exit_error("Command not found", data);
	}
	data->cmd2_path = find_path(data->cmd2[0], envp);
	if (!data->cmd2_path)
	{
		perror(data->cmd2[0]);
		exit_error("Command not found", data);
	}
}





int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	if (argc != 5)
		return (1);
	
	ft_bzero(&data, sizeof(data));
	init_data(argv, envp, data);

}





//cmd1[0] is the function name
int	main(int argc, char **argv, char **envp)
{




	char	**cmd1;
	char	**cmd2;
	char	*cmd2_path;
	char	*cmd1_path;
	int		pfd[2];
	pid_t	pid1;
	pid_t	pid2;
	
	int		file2_fd;

	

	cmd1 = ft_split(argv[2], ' ');
	if (cmd1 == NULL)
		return (1);
	cmd1_path = find_cmd_path(cmd1[0], envp);
	if (cmd1_path == NULL)
	{
		perror(cmd1[0]);
		ft_free_array(cmd1);
		exit (127);
	}

	cmd2 = ft_split(argv[3], ' ');
	if (cmd2 == NULL)
	{
		free(cmd1_path);
		ft_free_array(cmd1);
		return (1);
	}
	cmd2_path = find_path(cmd2[0], envp);
	if (cmd2_path == NULL)
	{
		perror(cmd2[0]);
		free(cmd1_path);
		ft_free_array(cmd1);
		ft_free_array(cmd2);
		exit (127);
	}

//////////////////////////////////////////////////////
	if (pipe(pfd) == -1)
		return (1); // handle error
	pid1 = fork();
	if (pid == -1)
		return (1); // handle error
	if (pid == 0)
	{
		file1_fd = open(argv[1], O_RDONLY);
		if (file1_fd == -1)
		{
			perror(argv[1]);
			free(cmd1_path);
			free(cmd1_path2);
			ft_free_array(cmd1);
			ft_free_array(cmd2);
			exit(1);
		}

		dup2(file1_fd, 0);
		close(file1_fd);
		dup2(pfd[1], 1);
		close(pfd[1]);
		close(pfd[0]);
		execve(cmd1_path, cmd1, envp);
		perror(cmd1[0]);
		free(cmd1_path);
		ft_free_array(cmd1);
		free(cmd2_path);
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
				free(cmd1_path);
				ft_free_array(cmd1);
				ft_free_array(cmd2);
				free(cmd2_path);
				exit(1);
			}
			dup2(file2_fd, 1);
			close(file2_fd);
			dup2(pfd[0], 0);
			close(pfd[1]);
			close(pfd[0]);
			execve(cmd2_path, cmd2, envp);
			perror(cmd2[0]);
			free(cmd1_path);
			ft_free_array(cmd1);
			free(cmd2_path);
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
			free(cmd1_path);
			free(cmd2_path);
		}
		
	}
}
