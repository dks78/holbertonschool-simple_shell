#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void execute_command(char *command)
{
    pid_t pid;
    char *args[100];
    char *token = strtok(command, " ");
    int i = 0;

    while (token != NULL && i < 99)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {

        if (execvp(args[0], args) == -1)
        {
            perror("exec");
            exit(EXIT_FAILURE);
        }
    }
}
int main() {
    char command[] = "ls -l";
    execute_command(command);
    return 0;
}