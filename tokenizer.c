#include "simple_shell.h"

/**
 * tokenizer - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str)
{
    char **tokens;
    char *token;
    unsigned int i;

    if (str == NULL)
    {
        fprintf(stderr, "Error: Null input string\n");
        return (NULL);
    }

    tokens = malloc(sizeof(char *) * BUFFER);
    if (tokens == NULL)
    {
        perror("Malloc failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(str, "\n\t\r ");
    i = 0;

    while (token != NULL)
    {
        if (i >= BUFFER - 1)
        {
            fprintf(stderr, "Error: Too many tokens\n");
            free(tokens);
            return (NULL);
        }
        tokens[i] = token;
        token = strtok(NULL, "\n\t\r ");
        i++;
    }

    tokens[i] = NULL;
    return (tokens);
}
