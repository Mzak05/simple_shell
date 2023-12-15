#include "shell.h"
/**
**exitsh - bye
**Return: bye
**/

	int exitsh(void)
	{
		return (-1);
	}


/**
**printenv - bye
**Return: bye
**/

	int printenv(void)
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
