#include "shell.h"

/**
 * _getline - ieiei
 * @tpr: eoeoe
 * Return: rruru
 */
char *_getline(FILE *tpr)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, tpr);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
