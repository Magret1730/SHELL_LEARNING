#include "main.h"
/**
 * main - building shell to imitate bash
 * @ac: count of argument
 * @argv: arguments
 * Return: 0, success
 */
int main(int ac, char **argv)
{
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	(void)ac;

	while (1)
	{
		_puts("$ ");
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == EOF)
		{
			if (feof(stdin))
				perror("Terminating shell");
			else
				perror("Error");
			break;
		}
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("Memory allocation error");
			break;
		}
		strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token) + 1);
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
	}
	free(lineptr_copy);
	free(lineptr);
	free(argv);
	return (0);
}
