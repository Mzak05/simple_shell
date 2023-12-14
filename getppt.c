#include "shell.h"
/**
 * getppt - inv
 * @storemycmd: dat
 * @storemypath: in
 */
void getppt(char *storemycmd, char *storemypath)
{
char *souka, *douka, *ddj;
int i = 0;
if (storemycmd[0] == '/')
{
while (storemycmd[i] != '\0')
{
if (storemycmd[i] == ' ')
{
break;
}
storemypath[i] = storemycmd[i];
i++;
}
storemypath[i] = '\0';
}
else
{
souka = getenvos("PATH");
if (souka == NULL)
return;

ddj = _strdup(souka);
douka = strtok(ddj, ":");
while (douka != NULL)
{
storemypath[0] = '\0';
_strcpy(storemypath, douka);
_strcat(storemypath, "/");
i = 0;
while (storemycmd[i] != '\0' && storemycmd[i] != ' ')
{
_strncat(storemypath, &storemycmd[i], 1);
i++;
}
if (access(storemypath, X_OK) == 0)
break;

douka = strtok(NULL, ":");
}
}
}
