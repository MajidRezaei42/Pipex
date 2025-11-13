/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:57:08 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/10 15:57:10 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Finds the value of the "PATH=" variable from the environment & 
*/
static char	**find_path_dirs(char **envp)
{
	int		i;
	char	*path_value;
	char	**path_dirs;

	i = 0;
	path_value = NULL;
	path_dirs = NULL;
	while ((envp[i] != NULL))
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_value = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (path_value == NULL)
		return (NULL);
	path_dirs = ft_split(path_value, ':');
	return (path_dirs);
}

/*
* Tries to find a valid, executable path for the command
* by searching through all directories in path_dirs.
*/
static char	*search_paths_for_cmd(char **path_dirs, char *cmd)
{
	int		i;
	char	*temp_path;
	char	*full_path;

	i = 0;
	temp_path = NULL;
	full_path = NULL;
	while ((path_dirs[i] != NULL))
	{
		temp_path = ft_strjoin(path_dirs[i], "/");
		if (temp_path == NULL)
			return (NULL);
		full_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (full_path == NULL)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char **envp, char *cmd)
{
	char	*full_path;
	char	**path_dirs;

	path_dirs = find_path_dirs(envp);
	if (path_dirs == NULL)
		return (NULL);
	full_path = search_paths_for_cmd(path_dirs, cmd);
	if (full_path == NULL)
	{
		ft_free_array(path_dirs);
		return (NULL);
	}
	ft_free_array(path_dirs);
	return (full_path);
}
