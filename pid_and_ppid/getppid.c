#include <stdio.h>
#include <unistd.h>

/**
 * main - getppid()
 * Description: getppid() returns the process ID of the parent of the
 * calling process.  This will be either the ID  of  the  process that  created
 * this process using fork(), or, if that process has already terminated, the
 * ID of the process to which this process has been reparented (either init(1)
 * or a "subreaper" process defined via the prctl(2) PR_SET_CHILD_SUB‐REAPER
 * operation).
 * Return: sucess
 */

int main(void)
{
	pid_t my_getppid;

	my_getppid = getppid();
	printf ("%u\n", my_getppid);
	return (0);
}
/**
 * $$ is defined to return the process ID of the parent in a subshell; from
 * the man page under "Special Parameters":$ Expands to the process ID of the
 * shell. In a () subshell, it expands to the process ID of the current shell,
 * not the subshell.
 *
 * echo $$ works the same as getppid(), the reason is what is stated above
 */
