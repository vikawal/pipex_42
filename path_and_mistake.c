/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_and_mistake.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:45:50 by vmyshko           #+#    #+#             */
/*   Updated: 2024/03/18 16:06:33 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
		{
			if (access(command, X_OK) == 0)
				return (command);
			free(command);
			msg_error("Command found but not executable/no rights", 126);
		}
		free(command);
		paths++;
	}
	return (NULL);
}

void	free_and_error(t_pipex *pipex, char *err, int error_code)
{
	child_free(pipex);
	msg_error(err, error_code);
}

void	first_child(t_pipex pipex, char **av, char **envp)
{
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error(ERR_INFILE, 0);
	close(pipex.tube[0]);
	if (dup2(pipex.tube[1], STDOUT_FILENO) == -1)
		msg_error("Error redirecting output, dup2. 1st child", 1);
	close(pipex.tube[1]);
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		msg_error("Error redirecting input, dup2. 1st child", 1);
	close(pipex.infile);
	if (!av[2][0])
	{
		parent_free(&pipex);
		msg_error("permission denied: empy argument", 1);
	}
	else
		pipex.cmd_args = ft_split(av[2], ' ');
	if (pipex.cmd_args == NULL)
		msg_error("Error splitting command, child 1", 1);
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
		free_and_error(&pipex, ERR_CMD, 127);
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		msg_error("Execution problem child 1", 1);
}

void	second_child(int ac, t_pipex pipex, char **av, char **envp)
{
	pipex.outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		msg_error(ERR_OUTFILE, 1);
	close(pipex.tube[1]);
	if (dup2(pipex.tube[0], STDIN_FILENO) == -1)
		msg_error("Error redirecting input, dup2. 2nd child", 1);
	close(pipex.tube[0]);
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		msg_error("Error redirecting output, dup2. 2nd child", 1);
	close(pipex.outfile);
	if (!av[3][0])
	{
		parent_free(&pipex);
		msg_error("Pipex: permission denied: emtpy argument", 1);
	}
	pipex.cmd_args = ft_split(av[3], ' ');
	if (pipex.cmd_args == NULL)
		msg_error("Error splitting command, child 2", 1);
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
		free_and_error(&pipex, ERR_CMD, 127);
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		msg_error("Execution problem child 2", 1);
}

void	msg_error(char *err, int error_code)
{
	perror(err);
	exit(error_code);
}
