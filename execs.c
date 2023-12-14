#include "shell.h"
/**
 * execs - inv
 * @cmdtosend: l
 */
void execs(char **cmdtosend)
{
int i;
char *fcmd;
pid_t forkpid;
fcmd = getppt(cmdtosend[0]);
if (fcmd == NULL)
return;
else
{
forkpid = fork();
if (forkpid == -1)
{
for (i = 0; cmdtosend[i]; i++)
{
free(cmdtosend[i]);
cmdtosend[i] = NULL;
}
free(fcmd);
fcmd = NULL;
free(cmdtosend);
cmdtosend = NULL;
exit(EXIT_FAILURE);
}
else if (forkpid == 0)
{
execve(fcmd, cmdtosend, environ);
perror("execve failed");
for (i = 0; cmdtosend[i]; i++)
{
free(cmdtosend[i]);
cmdtosend[i] = NULL;
}
free(fcmd);
fcmd = NULL;
free(cmdtosend);
cmdtosend = NULL;
exit(EXIT_FAILURE);
}
else
wait(NULL);
}
}
