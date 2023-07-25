#include "main.h"

char *locate(char *com)
{
    char *path, *cpy, *token, *file;
    int len, dir;
    struct stat buf;

    path = getenv("PATH");
    if (path)
    {
        cpy = strdup(path);

        len = strlen(com);

        token = strtok(cpy, ":");

        while (token != NULL)
        {
            dir = strlen(token);
            file = malloc(len + dir + 2);

            strcpy(file, token);
            strcat(file, "/");
            strcat(file, com);
            strcat(file, "\0");

            if (stat(file_path, &buf) == 0)
            {
                free(cpy);
                return (file);
            }
            else
            {
                free(path);
                token = strtok(NULL, ":");
            }
        }
        free(cpy);

        if (stat(com, &buf) == 0)
        {
            return (com);
        }

        return (NULL);
    }

    return (NULL);}