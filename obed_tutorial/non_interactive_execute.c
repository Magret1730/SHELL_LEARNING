#include "main.h"

void execmd(char **argv)
{
	char *command = NULL;
	char *file_path = NULL;

	if (argv)
	{
		/* get the command */
		command = argv[0];

		/* check if the command exists in the path */
		file_path = get_location(command);

		if (file_path)
		{
			/* execute the command with execve using the file path */
			if (execve(file_path, argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			printf("Command not found: %s\n", command);
		}
	}
}
