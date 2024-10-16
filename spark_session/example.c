/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:29:06 by vmyshko           #+#    #+#             */
/*   Updated: 2024/01/12 13:49:58 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

int pipex (const char *file1, const char *cmd1, const char *cmd2, const char *file2)
{
	int pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipex:pipe_mistake");
		return (1);
	}
	
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("pipex:fork_mistake");
		return (1);
	}

	if (pid == 0) //child process, cmd1
	{
		close(pipefd[0]); //closing reading part
		dup2(pipefd[1], STDOUT_FILENO); // redirecting standart output to pipe
		close(pipefd[1]);

		int file1_fd = open(file1, O_RDONLY);

		if (file1_fd == -1)
		{
			perror("pipex:open_mistake");
			return (1);
		}

		dup2(file1_fd, STDIN_FILENO);  // redirecting standart input to file1
		close(file1_fd);

		execl ("/usr/bin/ls", cmd1, (char *)NULL); //need function to find a path for command
		perror("execl");
		exit(1);
	}
	else // parent process
	{
		close(pipefd[1]); // closing writing pipe
		int file2_fd = open(file2, O_WRONLY | O_CREAT |O_TRUNC, 0644);

		if (file2_fd == -1)
		{
			perror("pipex:open_mistake");
			return (1);
		}

		dup2(file2_fd, STDOUT_FILENO); // Redirect standard output to go into file2
		close(file2_fd);

		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);

		execl ("/usr/bin/wc", cmd2, (char *)NULL);  //need function to find a path for command
		perror("execl");
		exit(1);
	}
	wait(NULL);
	return (0);
}

int main() {
    const char *file1 = "infile.txt";
    const char *cmd1 = "ls -l"; // works, but without flags -l -need to split it
    const char *cmd2 = "wc -l"; // works, but without flags -l
    const char *file2 = "outfile.txt";

    return pipex(file1, cmd1, cmd2, file2);
}

// A function that returns the full path of a command, or NULL if not found
char *find_path (char *command) {
    // Get the PATH environment variable
    char *path = getenv ("PATH");
    if (path == NULL) {
        return NULL;
    }
    // Make a copy of the path, as strtok modifies the string
    char *path_copy = strdup (path);
    if (path_copy == NULL) {
        return NULL;
    }
    // Split the path by ':' and search each directory for the command
    char *dir = strtok (path_copy, ":");
    while (dir != NULL) {
        // Construct the full path of the command
        char *full_path = malloc (strlen (dir) + strlen (command) + 2);
        if (full_path == NULL) {
            free (path_copy);
            return NULL;
        }
        sprintf (full_path, "%s/%s", dir, command);
        // Check if the command is executable
        if (access (full_path, X_OK) == 0) {
            // Found the command, return the full path
            free (path_copy);
            return full_path;
        }
        // Free the full path and try the next directory
        free (full_path);
        dir = strtok (NULL, ":");
    }
    // No matching command found, return NULL
    free (path_copy);
    return NULL;
}