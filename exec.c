#include "shell.h"

/**
 * exec -  execute processes
 * @args: arguments
 *
 * Return: 1 if successful and 0 otherwise
 */

int exec(char **args)
{
	int status;
	pid_t cpid = fork();

	if (cpid == 0)
	{
		if (execvp(args[0], args) == 1)
		{
			perror("Execvp error");
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
			waitpid(cpid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}