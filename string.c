#include "shell.h"

/**
 * _strcmp - eiei
 * @fam: dede
 * @variable: frfr
 * @lsp: frfr
 * Return: frfr
 */
int _strcmp(char *fam, char *variable, unsigned int lsp)
{
	unsigned int var_length;
	unsigned int i;

	var_length = _strlen(variable);
	if (var_length != lsp)
		return (-1);

	i = 0;
	while (fam[i] != '\0' && variable[i] != '\0')
	{
		if (fam[i] != variable[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strncmp - compvf
 * @fam: xc
 * @variable: vvvf
 * @lsp: gtgt
 * Return: hyhy
 */
int _strncmp(char *fam, char *variable, unsigned int lsp)
{
	unsigned int i;

	i = 0;
	while (i < lsp)
	{
		if (fam[i] != variable[i])
			return (-1);
		i++;
	}
	return (1);
}
