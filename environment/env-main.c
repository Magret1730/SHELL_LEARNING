#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

int main(int argc, char **argv, char **env)
{
	unsigned int i = 0;
	char **addr = env;

	(void)argc;
	(void)argv;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	printf("Adress of env is %p\n", *addr);
	return (0);
}
