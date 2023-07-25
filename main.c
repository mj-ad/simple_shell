#include "main.h"

int main(int argc, char *argv[])
{
    char *prompt = "#cisfun$ ";
    char *line = NULL;
    char *copy = NULL;
    char *del = " \n";
    size_t n = 0;
    int read;
    int ntokens = 0;
    char *token;
    int i;

    (void) argc;

    while (1)
    {
        printf("%s", prompt);
        read = getline(&line, &n, stdin);

        if (read == -1)
        {
            printf("Exiting shell....\n");
            return (-1);
        }

        copy = malloc(sizeof(char) * read);
        if (copy == NULL)
        {
            perror("Memory allocation error");
            return (-1);
        }

        strcpy(copy, line);

        token = strtok(line, del);

        while(token != NULL)
        {
            ntokens++;
            token = strtok(NULL, del);
        }
        ntokens++;

        argv = malloc(sizeof(char *) * ntokens);

        token = strtok(copy, del);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, del)
        }
        argv[i] = NULL;

        exec(argv);

    }

    free(line);
    free(copy);

    return (0);
}