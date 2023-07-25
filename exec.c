#include "main.h"

void exec(char **arg)
{
    char *com = NULL, *ac = NULL;

    if (arg)
    {
        com = arg[0];
    
        ac = locate(com);

        if (execve(com, arg, NULL) == -1)
        {
            perror("Error:");
        }
    }
}