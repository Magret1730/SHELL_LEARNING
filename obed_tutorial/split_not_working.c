#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - rough program on tokenizing(splitting) a string
 * but it isnt compiling
 */
int main(int argc, char**argv)
{
	char *prompt = "(My_shell) # ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	(void)argc;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		/*check if the getline function failed or reached EOF or user used ctrl + D*/
		if (nchars_read == -1)
		{
			printf("Exiting shell...\n");
			return (-1);
		}
	}

	/* allocate space for a copy of the lineptr */
	lineptr_copy = malloc(sizeof(char) * nchars_read);
	if (lineptr_copy == NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}

	/* copy lineptr to lineptr_copy */
	strcpy(lineptr_copy, lineptr);

	 /********** split the string (lineptr) into an array of words ********/
        /* calculate the total number of tokens */
	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	/* Allocate space to hold the array of strings */
	argv = malloc(sizeof(char *) * num_tokens);

	/* Store each token in the argv array */
	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim)
	}
	argv[i] = NULL;

	printf("%s\n", lineptr);
	
	/*not part of the shell project*/
	/* print the content of argv */
	for (counter = 0; counter<num_tokens-1; counter++)
	{
		printf("%s\n", argv[counter]);
	}

	/* free up allocated memory */
	free(lineptr);
	free(lineptr_copy);
	free(argv);
	free(argv[i]);

	return (0);
}
