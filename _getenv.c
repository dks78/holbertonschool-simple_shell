#include "simple_shell.h"
/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
/* cette variable va gérer ducpup les chemins dans le shell */
char *_getenv(const char *name)
{
	char **environ_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int path_length, environ_length, length, i;

	environ_length = 0;
	while (environ[environ_length] != NULL)
		environ_length++;
	environ_copy = NULL; /*on initialise une variable NULL pour copier avec la fonction copy_env() pour copier chaque chaine de 
    charactére de environs  */
	environ_copy = copy_env(environ_copy, environ_length);

	length = _strlen((char *)name);/*calcule la longeur e la chaine NAME*/
	i = 0;
	while (environ_copy[i] != NULL) /*parcourir chaque chaine de charactére dans while (environ_copy[i] != NULL)  */
	{
		variable = environ_copy[i];
		compare = _strncmp((char *)name, variable, length); /*ici compare et définie pour compare les chaine de charactére name , variable
        et lenght*/

		if (compare == 1) 
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			if (value == NULL)
			{
				errors(4);
				exit(EXIT_FAILURE);
			}

			path_length = _strlen(value);/*sotcker la longeur de la variable value et la sotcker dans path_lenght*/
			path = malloc(sizeof(char) * path_length + 1);
			if (path == NULL)
			{
				errors(3);
				return (NULL);
			}
			path = _strcpy(path, value);/*ensuite on copy path et value dans path*/
			free_dp(environ_copy, environ_length);/*libére la mémoire
            */
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * copy_env - copies environment variable
 * @environ_copy: pointer to copy of environment variable
 * @environ_length: length of environment variable
 * Return: double pointer to copy of environment variable
 */
char **copy_env(char **environ_copy, unsigned int environ_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;

	environ_copy = malloc(sizeof(char **) * (environ_length));
	if (environ_copy == NULL)
	{
		errors(3);
		return (NULL);
	}

	i = 0;
	while (i < environ_length)
	{
		variable = environ[i];
		variable_length = _strlen(variable);

		environ_copy[i] = malloc(sizeof(char) * variable_length + 1);
		if (environ_copy[i] == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(environ_copy[i], environ[i]);
		i++;
	}

	return (environ_copy);
}
