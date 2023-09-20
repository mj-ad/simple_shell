#include "shell.h"

/**
 * exec -  execute processes
 * @args: arguments
 *
 * Return: 1 if successful and 0 otherwise
 */

int exec(char **args)
{
	pid_t pid, cpid = fork();

	if (cpid == 0)
	{
		if (execvp(args[0], args) == 1)
		{
			perror("Error in child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (cpid < 0)
	{
		perror("Forking error");
	}
	else
	{
		do
		{
			pid = waitpid(cpid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}