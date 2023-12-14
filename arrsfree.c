#include "shell.h"
/**
 * arrsfree - lol
 * @cmdtosend: ii
 */
void arrsfree(char **cmdtosend)
{
int i;
if (cmdtosend != NULL)
{
for (i = 0; cmdtosend[i] != NULL; i++)
{
free(cmdtosend[i]);
cmdtosend[i] = NULL;
}
free(cmdtosend);
cmdtosend = NULL;
}
}
