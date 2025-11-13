/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:12:44 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/03 10:12:46 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **array)
{
	int	i;
	while (array[i])
	{
		free(array[i]);
		i ++;
	}
	free(array);
	return(NULL);
}

void	free_data(t_pipex *data)
{
	if (data->cmd1)
		ft_free_array(data->cmd1);
	if (data->cmd2)
		ft_free_array(data->cmd1);
	if (data->cmd1_path)
		free(data->cmd1_path);
	if (data->cmd2_path)
		free(data->cmd2_path);
}

void	exit_error(*msg, t_pipex *data)
{
	perror(msg);
	free_data(data);
	exit(EXIT_FAILURE);

}
