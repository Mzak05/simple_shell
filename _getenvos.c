#include "shell.h"
/**
 * _getenvos - famp
 * @fam: eno
 * Return: nop
 */
char *_getenvos(const char *fam)
{
	char **environ_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int path_length, environ_length, length, i;

	environ_length = 0;
	while (environ[environ_length] != NULL)
		environ_length++;
	environ_copy = NULL;
	environ_copy = cpenv(environ_copy, environ_length);

	length = _strlen((char *)fam);
	i = 0;
	while (environ_copy[i] != NULL)
	{
		variable = environ_copy[i];
		compare = _strncmp((char *)fam, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			if (value[_strlen(value) - 1] == '\0')
			{
				noway(4);
				exit(EXIT_FAILURE);
			}
			path_length = _strlen(value);
			path = malloc(sizeof(char) * path_length + 1);
			if (path == NULL)
			{
				noway(3);
				return (NULL);
			}
			path = _strcpy(path, value);
			getoutmini(environ_copy, environ_length);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * cpenv - pdep
 * @cpy: pdep
 * @leoenv: ded
 * Return: sdcsd
 */
char **cpenv(char **cpy, unsigned int leoenv)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;

	cpy = malloc(sizeof(char **) * (leoenv));
	if (cpy == NULL)
	{
		noway(3);
		return (NULL);
	}

	i = 0;
	while (i < leoenv)
	{
		variable = environ[i];
		variable_length = _strlen(variable);

		cpy[i] = malloc(sizeof(char) * variable_length + 1);
		if (cpy[i] == NULL)
		{
			noway(3);
			return (NULL);
		}
		_strcpy(cpy[i], environ[i]);
		i++;
	}

	return (cpy);
}
