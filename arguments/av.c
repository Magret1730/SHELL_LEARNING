#include <stdio.h>
/**
 * main - program that prints all the arguments, without using ac
 *
 * Return: 0, success
 */
int main(int argc, char **argv)
{
	
	(void)argc;
	
	if (argv != NULL)
	{
		while (*argv != NULL)
		{
			printf("%s ", *argv);
			argv++;
		}
	}
	printf("\n");
	return (0);
}
