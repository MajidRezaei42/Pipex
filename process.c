/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:30:15 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/11 12:30:16 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    parent_process(t_pipex *data)
{
	close(data->pfd[1]);
	close(data->pfd[0]);
	wait(NULL);
	wait(NULL);
	free_data(&data)
}

void    child_process_one(char **argv, char **envp, t_pipex *data)
{
	int		file1_fd;

	file1_fd = open(argv[1], O_RDONLY);
	if (file1_fd == -1)
	{
		perror(argv[1]);
		exit_error("Cannot open file to read", &data)
	}
	dup2(file1_fd, 0);
	close(file1_fd);
	dup2(data->pfd[1], 1);
	close(data->pfd[1]);
	close(data->pfd[0]);
	execve(data->cmd1_path, data->cmd1, envp);
	perror(data->cmd1[0]);
	exit_error("Cannot execute the first command", &data)

}

void    child_process_two(char **argv, char **envp, t_pipex *data)
{
	int		file1_fd;

	file2_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2_fd == -1)
	{
		perror(argv[4]);
		exit_error("Cannot open file to write/modify", &data)
	}
	dup2(file2_fd, 1);
	close(file2_fd);
	dup2(data->pfd[0], 0);
	close(data->pfd[1]);
	close(data->pfd[0]);
	execve(data->cmd2_path, data->cmd2, envp);
	perror(data->cmd2[0]);
	exit_error("Cannot execute the second command", &data)
}