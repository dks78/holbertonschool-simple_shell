#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - Un interpréteur de commandes simple.
 *
 * Return: Toujours 0.
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *command[2];

    while (1) {

        printf("#cisfun$ ");
        

        nread = getline(&line, &len, stdin);

        if (nread == -1) {
            printf("\n");
            break;
        }


        line[strcspn(line, "\n")] = 0;


        if (strlen(line) == 0) {
            continue;
        }


        command[0] = line;
        command[1] = NULL;


        if (execve(command[0], command, NULL) == -1) {

            perror("./shell");
        }
    }


    free(line);
    return 0;
}
