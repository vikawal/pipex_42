/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:26:04 by vmyshko           #+#    #+#             */
/*   Updated: 2024/03/18 15:44:31 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

char	*find_path(char **envp, t_pipex *pipex)
{
	int		cond;
	int		i;

	i = 0;
	cond = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			cond = 1;
		i++;
	}
	if (cond == 0)
	{
		close_pipes(pipex);
		close(pipex->infile);
		close(pipex->outfile);
		msg_error(ERR_ENVP, 1);
	}
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	handle_most_errors(int ac, t_pipex *pipex)
{
	if (ac != 5)
		msg_error(ERR_INPUT, 1);
	if (pipe(pipex->tube) < 0)
		msg_error(ERR_PIPE, 1);
}

void	handle_path_children(int ac, char **envp, t_pipex *pipex, char **av)
{
	pipex->paths = find_path(envp, pipex);
	pipex->cmd_paths = ft_split(pipex->paths, ':');
	if (pipex->cmd_paths == NULL)
		msg_error("Error splitting command", 1);
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		msg_error("Error forking 1", 1);
	if (pipex->pid1 == 0)
		first_child(*pipex, av, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		msg_error("Error forking 2", 1);
	if (pipex->pid2 == 0)
		second_child(ac, *pipex, av, envp);
	close_pipes(pipex);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		status;

	handle_most_errors(ac, &pipex);
	handle_path_children(ac, envp, &pipex, av);
	if (waitpid(pipex.pid1, NULL, 0) == -1)
		msg_error("Error waiting for first child", 1);
	if (waitpid(pipex.pid2, &status, 0) == -1)
		msg_error("Error waiting for second child", 1);
	parent_free(&pipex);
	return (WEXITSTATUS(status));
}
