#include "shell.h"
/**
 * splitCmd - lo
 * @storemycmd: inf
 * Return: i
 */
char **splitCmd(char *storemycmd)
{
char **cmdtosend = malloc(100 * sizeof(char *));
int i = 0;
char *souka, *cpy;
if (cmdtosend == NULL)
{
return (NULL);
}
cpy = _strdup(storemycmd);
souka = strtok(cpy, " \t\n");
if (souka == NULL)
{
free(cmdtosend);
return (NULL);
}
while (souka != NULL && i < 99)
{
cmdtosend[i++] = _strdup(souka);
souka = strtok(NULL, " \t\n");
}
free(cpy);
cmdtosend[i] = NULL;
return (cmdtosend);
}
