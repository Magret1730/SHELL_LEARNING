#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - program that executes the command
 *
 * Description: program that executes the command
 * ls -l /tmp in 5 different child processes
 * Each child should be created by the same process (the father)
 * Wait for a child to exit before creating a new child
 * Return: 0, success
 */

int main(void)
{
	pid_t parent_pid;
	pid_t child_pid;
	int status;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	parent_pid = getpid(); /* Store the parent process ID */

	for (int i = 0; i < 5; i++)
	{
		child_pid = fork(); /* Create a child process */

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (child_pid == 0)
		{
			/* Child process executes the command */
			printf("Child process ID: %d\n", getpid());
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
		{
			/* Parent process waits for the child to finish */
			printf("Parent process ID: %d, waiting for child %d\n", parent_pid, child_pid);
			wait(&status);
			printf("Child %d finished\n", child_pid);
		}
	}
	
	printf("All done!\n");

	return (0);
}
