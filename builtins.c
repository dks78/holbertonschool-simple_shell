#include "simple_shell.h"
/**
**shell_exit - exits the shell
**Return: void
**/

int shell_exit(void)
{
	return (-1);
}


/**
**shell_env - prints environment
**Return: void
**/
	/*ici on gére les envirnement et aussi pour quitter le shell */
int shell_env(void)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
