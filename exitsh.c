#include "shell.h"
/**
 * exitsh - fct
 * @storemycmd: i
 */
void exitsh(char *storemycmd)

{
if (storemycmd == NULL)
{
free(storemycmd);
exit(EXIT_SUCCESS);
}
else
{
free(storemycmd);
exit(EXIT_SUCCESS);
}
}
