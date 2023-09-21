#include "shell.h"

/**
 * split_line - splits the line gotten from get line into multiple strings
 * @line: line to be split
 * 
 * Return: an array of split lines
*/

char **split_line(char *line)
{
	char **argv = NULL;
	char *delim = ' ';
	size_t word = 0;
	size_t size = strlen(line);
	size_t i = 0, j = 0;
	char prev = '\0';

	if (strtok(line, delim) != NULL)
	{
		++word;
	}
	while (strtok(NULL, delim))
	{
		++word;
	}

	argv = malloc(sizeof(char *) * (word + 1));
	for (i = 0; i < size; ++i)
	{
		if (line[i] != '\0' && prev == '\0')
		{
			argv[j] = line + i, ++j;
		}
		prev = line[i];
	}
	argv[j] = NULL;
	return (argv);
}
