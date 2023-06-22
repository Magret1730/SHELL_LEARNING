#include "main.h"

void execmd(char **argv)
{
    pid_t child_pid;
    int status, signal_number, exit_status;
    char *command;

    if (argv && argv[0])
    {
        command = argv[0];

        if (strcmp(command, "cd") == 0)
        {
            if (argv[1])
            {
                if (chdir(argv[1]) == -1)
                {
                    perror("cd error");
                }
            }
            return;
        }

        child_pid = fork();

        if (child_pid == -1)
        {
            perror("fork error");
            return;
        }
        else if (child_pid == 0)
        {
            if (execve(command, argv, NULL) == -1)
            {
                perror("Command execution error");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            waitpid(child_pid, &status, 0);

            if (WIFEXITED(status))
            {
                exit_status = WEXITSTATUS(status);
                printf("Child process exited with status: %d\n", exit_status);
            }
            else if (WIFSIGNALED(status))
            {
                signal_number = WTERMSIG(status);
                printf("Child process terminated by signal: %d\n", signal_number);
            }
        }
    }
}

