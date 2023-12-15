#include "shell.h"

/**
 * splitcmd - voov
 * @chaimae: vv
 * Return: ppt
 */
char **splitcmd(char *chaimae)
{
	char **tokens;
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		noway(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(chaimae, "\n\t\r ");

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
