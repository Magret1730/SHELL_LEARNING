#include "main.h"

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		command = argv[0]; /* get the command*/

		/* generate the path to this command before passing it to execve */
		actual_command = get_location(command);
		
		/* execute the command with execve*/
		if (execve(actual_command, argv, NULL) == -1)
			perror("Error:");
	}
}
