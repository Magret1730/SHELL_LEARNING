#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - simple shell build from someone
 *
 * Description: program displays a prompt
 * gets input from user
 * diplays the input
 * the program is terminated until ctrl + d is pressed
 * Return: success
 */
#define MAX_COMMAND_LENGTH 100

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	size_t command_length;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		
		if (fgets(command, sizeof(command), stdin) == NULL)
			break;

		command_length = strlen(command);
		if (command[command_length - 1] == '\n')
			command[command_length - 1] = '\0';
		printf("%s\n", command);
	}

	printf("\n");
	return (EXIT_SUCCESS);
}

