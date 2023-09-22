#include "shell.h"

/**
 * read_line - reads line from buffer
 *
 * Return: line read
 */

char *read_line(void)
{
	char *line = NULL;
	ssize_t buf = 0;
	ssize_t read;

	if (get_line(&line, &buf, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Could not read line from stdin");
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	return (line);
}
