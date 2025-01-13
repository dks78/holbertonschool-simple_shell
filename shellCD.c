#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "simple_shell.h"




int shell_cd(char **tokens)
{
    if (tokens[1] == NULL)  
    {
        char *home = getenv("HOME");
        if (home == NULL)
        {
            perror("cd");
            return 1;
        }
        if (chdir(home) != 0)
        {
            perror("cd");
            return 1;
        }
    }
    else if (tokens[1] != NULL && strcmp(tokens[1], "-") == 0)
    {
        char *oldpwd = getenv("OLDPWD");
        if (oldpwd == NULL)
        {
            perror("cd");
            return 1;
        }
        if (chdir(oldpwd) != 0)
        {
            perror("cd");
            return 1;
        }
    }
    else
    {
        if (chdir(tokens[1]) != 0)
        {
            perror("cd");
            return 1;
        }
    }
    return 0;
}