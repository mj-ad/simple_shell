#include "shell.h"

/**
 * get_line - get line from stdin
 * @line: line gotten is stored here
 * @n: number of bytes of buffer
 * @stream: Input
 * 
 * Return: num of chars read
*/

ssize_t get_line(char **line, size_t *n, FILE *stream)
{
	size_t size = *n;
	char *buf = *line;
	int c;
	size_t i =0;
	char *nbuf = realloc(buf, size);

	if (line == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

	while ((c =fgetc(stream)) != EOF)
	{
		if (i >= size - 1)
		{
			size *= 2;
			if (nbuf == NULL)
			{
				free(buf);
				return (-1);
			}
			buf = nbuf;
		}

		buf[i++] = c;
		if (c == '\n')
		{
			break;
		}
	}

	buf[i] = '\0';
	*line = buf;
	*n = size;
	return (i);
}
