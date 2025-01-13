#include "simple_shell.h"

/**
 * errors - prints errors based on case
 * @error: error number associated with perror statement
 * Return: void
 */
void errors(int error)
{
    if (error == 1) {
        write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));
        perror("Error");
    }
    else if (error == 2) {
        perror("Error");
    }
    else if (error == 3) {
        write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));
    }
    else if (error == 4) {
        write(STDERR_FILENO, ERR_PATH, _strlen(ERR_PATH));
    }
}