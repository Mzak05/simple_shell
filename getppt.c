#include "shell.h"
/**
 * getppt - oo
 * @storemycmd: iii
 * Return: iii
 */
char *getppt(char *storemycmd)
{
char *souka, *douka, *fcmd, *full_path;
if (storemycmd[0] == '/')
{
if (access(storemycmd, X_OK) == 0)
{
return (_strdup(storemycmd));
}
return (NULL);
}
else
{
souka = getenvos("PATH");
if (souka == NULL)
{
return (NULL);
}
douka = _strdup(souka);
fcmd = strtok(douka, ":");
while (fcmd != NULL)
{
full_path = malloc(_strlen(fcmd) + 1 + _strlen(storemycmd) + 1);
if (full_path != NULL)
{
_strcpy(full_path, fcmd);
_strcat(full_path, "/");
_strcat(full_path, storemycmd);
if (access(full_path, X_OK) == 0)
{
free(douka);
return (full_path);
}
free(full_path);
}
fcmd = strtok(NULL, ":");
}
free(douka);
return (NULL);
}
}
