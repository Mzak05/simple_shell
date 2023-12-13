#include "shell.h"
/**
 * exitsh - fct
 * @storemycmd: ii
 * @sta: ii
 */
void exitsh(char *storemycmd, int *sta)
{
free(storemycmd);
exit(*sta);
}
