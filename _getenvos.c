#include "shell.h"
/**
 * getenvos - inv
 * @data: dat
 * Return: info
 */
char *getenvos(char *data)
{
char *spr, *valo;
int i = 0;
for (i = 0; environ[i] != NULL; i++)
{
spr = strtok(environ[i], "=");
if (spr != NULL && strcmp(spr, data) == 0)
{
valo = strtok(NULL, "=");
if (valo != NULL)
{
return (valo);
}
}
}
return (NULL);
}
