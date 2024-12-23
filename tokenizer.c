#include "simple_shell.h"

/**
 * tokenizer - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str)/*Cette fonctionsert à découper une chaîne de caractères (str) en plusieurs "tokens" 
*/
{
	char **tokens;
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n\t\r ");

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}
