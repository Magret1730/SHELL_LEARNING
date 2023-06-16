#include <stdio.h>
#include <stdlib.h>

/**
 * main - building a simple shell tutorial with Obed
 * @ac: conut of arguments
 * @argv: arguments passed
 *
 * Description: the command displays a prompt to shell,
 * gets input from end users
 * and prints the input
 * The program is terminated until ctrl + d is pressed
 * Return: 0, success
 */
int main(int ac, char **argv)
{
	char *prompt = "(Eshell) $ ";
	char *lineptr; /**lineptr_copy = NULL;*/
	size_t n = 0;
	ssize_t nchars_read;
	/*const char *delim = " \n";*/

	/* declaring void variables */
	(void)ac;
	(void)argv;
	
	while (1) /*it creates infinite loop*/
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read < 0)
		{
			printf("Exiting shell...\n");
			return (-1);
		}
		printf("%s\n", lineptr);
		printf("%ld\n", nchars_read);
	}
	free(lineptr);
	return (0);
}
