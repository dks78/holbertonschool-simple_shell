#include <unistd.h>
#include <stdlib.h>
#include "simple_shell.h" 
int main(void)
{
    char *command = NULL;
    size_t len = 0;

    while (1) {
        printf("($) ");
        if (getline(&command, &len, stdin) == -1) {
            printf("\n");
            break;
        }
        handle_command(command);
    }
    free(command);
    return (0);
}
