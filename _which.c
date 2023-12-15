#include "shell.h"
/**
 * _which - iru
 * @storemycmd: lolo
 * @powerful: lolo
 * @souka: lop
 * Return: od
 */
char *_which(char *storemycmd, char *powerful, char *souka)
{
	unsigned int command_length, path_length, original_path_length;
	char *path_copy, *token;

	command_length = _strlen(storemycmd);
	original_path_length = _strlen(souka);
	path_copy = malloc(sizeof(char) * original_path_length + 1);
	if (path_copy == NULL)
	{
		noway(3);
		return (NULL);
	}
	_strcpy(path_copy, souka);
	token = strtok(path_copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_length = _strlen(token);
		powerful = malloc(sizeof(char) * (path_length + command_length) + 2);
		if (powerful == NULL)
		{
			noway(3);
			return (NULL);
		}
		_strcpy(powerful, token);
		powerful[path_length] = '/';
		_strcpy(powerful + path_length + 1, storemycmd);
		powerful[path_length + command_length + 1] = '\0';
		if (access(powerful, X_OK) != 0)
		{
			free(powerful);
			powerful = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_copy);
	return (powerful);
}
