#include "shell.h"
/**
 * printvile - inv
 * @sta: i
 */
void printvile(int *sta)
{
char **env = environ;
int i = 0;
for (i = 0; env[i]; i++)
{
write(STDOUT_FILENO, env[i], _strlen(env[i]));
write(STDOUT_FILENO, "\n", 1);
}
(*sta) = 0;
}
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
/**
 * getcmd - inv
 * @storemycmd: dat
 * @storemypath: in
 * @cmdtosend: lo
 */
void getcmd(char *storemycmd, char *storemypath, char **cmdtosend)
{
int i, j;
getppt(storemycmd, storemypath);
j = 0, i = 0;
cmdtosend[j] = &storemypath[0];
j++;
while (storemycmd[i] != '\0')
{
if (storemycmd[i] == ' ')
{
storemycmd[i] = '\0';
i++;
cmdtosend[j] = &storemycmd[i];
j++;
}
i++;
}
cmdtosend[j] = NULL;
}
/**
 * execs - inv
 * @storemycmd: dat
 * @storemypath: in
 * @cmdtosend: l
 */
void execs(char *storemycmd, char *storemypath, char **cmdtosend)
{
char *env[] = {NULL};
pid_t forkpid = fork();
if (forkpid == -1)
{
perror("you have a fork issue");
free(storemycmd);
exit(EXIT_FAILURE);
}
else if (forkpid == 0)
{
getcmd(storemycmd, storemypath, cmdtosend);
execve(storemypath, cmdtosend, env);
perror("execve failed");
exit(EXIT_FAILURE);
}
else
wait(NULL);
}
/**
 * main - inv
 * Return: info
 */
int main(void)
{
char yassirwait[] = "#cisfun$ ", storemypath[100];
char *storemycmd = NULL, *cmdtosend[100];
size_t getmycmdcnt = 0, storemygetline = 0;
int sta = 0;
while (1)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, yassirwait, strlen(yassirwait));
}
storemygetline = getline(&storemycmd, &getmycmdcnt, stdin);
if ((int)storemygetline == -1)
{
if (isatty(STDIN_FILENO))
{
perror("get line returned a bad out");
}
free(storemycmd);
exit(EXIT_FAILURE);
}
storemycmd[storemygetline - 1] = '\0';
if (_strcmp(storemycmd, "exit") != 0)
{
if (_strcmp(storemycmd, "env") == 0)
{
printvile(&sta);
}
else
{
execs(storemycmd, storemypath, cmdtosend);
}
}
else
{
exitsh(storemycmd);
}
}
free(storemycmd);
return (0);
}
