/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:42:55 by vmyshko           #+#    #+#             */
/*   Updated: 2024/03/18 11:43:16 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include "LIBFT/libft.h"

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>

# define ERR_ENVP "Pipex: Error envp !!!"
# define ERR_INPUT "Pipex: invalid number of arguments"
# define ERR_INFILE "Pipex:Infile"
# define ERR_OUTFILE "Pipex: Outfile"
# define ERR_PIPE "Pipex: Pipe"
# define ERR_CMD "Pipex: Command not found"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

void	first_child(t_pipex pipex, char **av, char **envp);
// void	second_child(t_pipex pipex, char *argv[], char *envp[]);
void	second_child(int ac, t_pipex pipex, char **av, char **envp);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
// int		msg(char *err);
// void	msg_error(char *err, int error_code);
void	msg_error(char *err, int error_code);

#endif