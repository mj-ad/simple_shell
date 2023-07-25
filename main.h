#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys.h>

void exec(char **arg);
char *locate(char *com);

#endif /* MAIN_H */