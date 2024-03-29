#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

char *read_line(void);
char **split_line(char *line);
int exec(char **args);
ssize_t get_line(char **line, size_t *n, FILE *stream);

#endif /* SHELL_H */
