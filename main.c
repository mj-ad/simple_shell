#include "shell.h"

/**
 * main - Entry point
 * @ac: counter
 * @av: arguments
 *
 * Return: always 0
 */

int main(void)
{
	char *line;
	char **args;
	int stats;

	do
	{
		printf("$ ");
		line = read_line();
		args = split_line(line);
		stats = exec(args);

		free(line);
		free(args);
	} while (stats);
	return (0);
}
