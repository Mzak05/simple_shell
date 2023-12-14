#include "shell.h"
/**
 * getenvos - --
 * @data: iii
 * Return: iii
 */
char *getenvos(char *data)
{
int i;
size_t len = _strlen(data);
for (i = 0; environ[i] != NULL; i++)
{
if (_strncmp(environ[i], data, len) == 0 && environ[i][len] == '=')
{
return (_strdup(environ[i] + len + 1));
}
}
return (NULL);
}
