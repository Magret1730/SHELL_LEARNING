#include <stdio.h>

extern char **environ;

char *_getenv(const char *name)
{
	char **env = environ, *present;
	int i;

	/* Iterate over the environment variables */
	while (*env != NULL)
	{
		present = *env;
		i = 0;

		/* Find the position of the '=' character */
		while (present[i] != '=' && present[i] != '\0')
			i++;

		/* Check if the variable name matches */
		if (strcmp(name, current) == 0 && current[i] == '\0')	
			/* Return a pointer to the value part of the variable */
			return (&present[i + 1]);
		env++;
    }
	/* Variable not found */
	return (NULL);
}

int main(void)
{
	char *path = _getenv("PATH");

	if (path != NULL)
		printf("PATH: %s\n", path);
	else
		printf("PATH environment variable not found.\n");

	return (0);
}
