#include "main.h"

void execmd(char **argv)
{
	pid_t child_pid;
	int status;

	if (argv)
	{
		/* Fork a child process */
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork error");
			return;
		}
		else if (child_pid == 0)
		{
			/* Child process */

			/* Execute the command */
			execve(argv[0], argv, NULL);

			/* If execvp fails, output an error message */
			perror("Command execution error");
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */

			/* Wait for the child process to complete */
			waitpid(child_pid, &status, 0);
			
			/* Check if the child process terminated normally */
			if (WIFEXITED(status))
			{
				int exit_status = WEXITSTATUS(status);
				printf("Child process exited with status: %d\n", exit_status);
			}
			else if (WIFSIGNALED(status))
			{
				int signal_number = WTERMSIG(status);
				printf("Child process terminated by signal: %d\n", signal_number);
			}
		}
	}
}

