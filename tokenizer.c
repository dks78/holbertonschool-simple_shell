#include "simple_shell.h"

/**
 * tokenizer - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str)/*Cette fonctionsert à découper une chaîne de caractères (str) en plusieurs "tokens" 
*/
/*cette fonction va permetre au shell de comprendre les commande comme ls -l ect */
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

	token = strtok(str, "\n\t\r ");/*les chaine de charactére decoupé*/
	/*seront stocké dans toke, */

	i = 0;
	while (token != NULL)/*tan que token n'est pas NULL , on va continué a découpe les chaines */
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}

	tokens[i] = NULL;;/*sert a marque la fin du tableau uen fois que*/
	/*une fois que tous les tokens ont été extrais et stocké danstokens */

	return (tokens);
}
