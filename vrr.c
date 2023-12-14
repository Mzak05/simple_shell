#include "shell.h"
/**
 * main - inv
 * @argc: inf
 * @argv: in
 * Return: info
 */
int main(int argc, char *argv[])
{
char **cmdtosend;
char *storemycmd = NULL;
char yassirwait[] = "$ ";
size_t storemygetline = 0, getmycmdcnt = 0;
int sta = 0;
(void)argc;
(void)argv;
while (1)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, yassirwait, 2);
}
storemygetline = getline(&storemycmd, &getmycmdcnt, stdin);
if ((int)storemygetline == -1)
{
if (isatty(STDIN_FILENO))
{
perror("get line returned a bad out");
}
free(storemycmd);
return (sta);
}
storemycmd[storemygetline - 1] = '\0';
cmdtosend = splitCmd(storemycmd);
if (cmdtosend == NULL)
{
continue;
}
execs(cmdtosend);
}
free(storemycmd);
return (0);
}
