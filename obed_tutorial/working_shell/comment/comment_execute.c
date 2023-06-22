#include "main.h"

void execmd(char **argv)
{
    pid_t child_pid;
    int status; /*exit_status, signal_number;*/
    char *command_path;


    if (argv)
    {
        /* Get the resolved path for the command */
        command_path = get_location(argv[0]);

        if (command_path == NULL)
        {
            /*fprintf(stderr, "Command not found: %s\n", argv[0]);*/
            perror("Command not found");
		return;
        }

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

            /* Print the command being executed */
            /*printf("Executing command: %s\n", command_path);*/

            /* Execute the command */
            execve(command_path, argv, NULL);

            /* If execve fails, output an error message */
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
                /*exit_status = */WEXITSTATUS(status);
                /*printf("Child process exited with status: %d\n", exit_status);*/
            }
            else if (WIFSIGNALED(status))
            {
                /*signal_number = */WTERMSIG(status);
                /*printf("Child process terminated by signal: %d\n", signal_number);*/
            }
        }

        /* Free the allocated command path */
        free(command_path);
    }
}

