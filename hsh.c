#include "shell.h"
/**
 * main - ttp
 * Return: for
 */
int main(void)
{
	char *line, *path, *fullpath;
	char **tokens;
	int flag, builtin_status, child_status;
	struct stat buf;

	while (TRUE)
	{
		pro(buf, STDIN_FILENO);
		line = _getline(stdin);
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		tokens = splitcmd(line);
		if (tokens[0] == NULL)
			continue;
		builtin_status = blexe(tokens);
		if (builtin_status == 0 || builtin_status == -1)
		{
			free(tokens);
			free(line);
		}
		if (builtin_status == 0)
			continue;
		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);
		flag = 0;
		path = _getenvos("PATH");
		fullpath = _which(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1;
		child_status = forkpid(fullpath, tokens);
		if (child_status == -1)
			noway(2);
		getout(tokens, path, line, flag, fullpath);
	}
	return (0);
}
