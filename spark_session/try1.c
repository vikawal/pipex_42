#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

// void dum (int *number)
// {
// 	*number = 42;
// }
// int main()
// {
// 	int num = 0;
// 	dum(&num);
// 	printf("%d\n", num);
// }

int main()
{
	const char *file1 = "text.txt";
	int file1_fd = open(file1, O_WRONLY | O_CREAT |O_TRUNC, 0644);
	dup2(file1_fd, STDOUT_FILENO);
	write(file1_fd, "File: Hello, world!\n", 20);
	write(1, "OUTOUT: Hello, world!\n", 22);

}
wife


// int main()
// {
// 	int status = 42;
// 	printf("Start: %d\n", status);
// 	int pid = fork();
// if (pid == 0)
// {
// 	printf("Child works\n");
// 	printf("child pid: %d\n", pid);
// 	char *argv[3];
// 	argv[0] = "/bin/ls";
// 	argv[1] = "-l";
// 	argv[2] = NULL;
// 	char *path = "/bin/ls";
// 	printf("IT IS HERE WE START EXECVE\n"); // not printed
// 	execve(path, argv, (void*)0); 
// 	printf("IT IS HERE\n"); // not printed
	
// }
	
// else
// {
// 	printf("Parent will start waiting, parend pid: %d\n", pid);
// 	wait(&status);
// 	printf("Child status FOR PARENT after wait: %d\n", status);
// 	printf("Finish\n");
// }
	 
// return 0;

// }

// int main()
// {
// 	char *argv[3];
// 	argv[0] = "/bin/ls";
// 	argv[1] = "-l";
// 	argv[2] = NULL;
// 	// char *argv[] = {"/bin/ls","ls", "-l"};
// 	char *path = "/bin/ls";
// 	execve(path, argv, (void*)0); 
// 	printf("IT IS HERE\n");
// }
