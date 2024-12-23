#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
/**
 * get_command_path - Finds the full path of the command.
 * @cmd: The user input command.
 * @env: The environment variables (unused).
 *
 * Return: The full path of the command or NULL if not found.
 */
char *get_command_path(char *cmd, char __attribute__((unused)) **env)
{
    char *path;
    char *dir;
    char *full_path;
    char *token;
    path = getenv("PATH");
    if (cmd[0] == '/')
    {
        return (strdup(cmd));  /* Return the command if it's already an absolute path */
    }
    token = strtok(path, ":");
    while (token != NULL)
    {
        dir = token;
        full_path = malloc(strlen(dir) + strlen(cmd) + 2);
        if (full_path == NULL)
        {
            perror("malloc");
            exit(1);
        }
        sprintf(full_path, "%s/%s", dir, cmd);
        if (access(full_path, X_OK) == 0)
        {
            return (full_path);  /* Return the path if the command exists */
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    return (NULL);  /* Command not found */
}
