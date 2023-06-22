#include <stdio.h>

extern char **environ;

int main(int argc, char **argv)
{
	char **env = environ;
	int i = 0;

	if (env == NULL)
		puts("Unavailable environment variable\n");
	else
	{
		while (env[i] != NULL)
		{
			puts(env[i]);
			i++;
		}
		printf("Address of environ is %p\n", *env);
	}
	return (0);
}
