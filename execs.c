#include "shell.h"
/**
 * execs - inv
 * @cmdtosend: l
 */
void execs(char **cmdtosend)
{
int i;
pid_t forkpid = fork();
if (forkpid == -1)
{
perror("you have a fork issue");
for (i = 0; cmdtosend[i]; i++)
{
free(cmdtosend[i]);
cmdtosend[i] = NULL;
}
free(cmdtosend);
cmdtosend = NULL;
exit(EXIT_FAILURE);
}
else if (forkpid == 0)
{
execve(cmdtosend[0], cmdtosend, environ);
perror("execve failed");
for (i = 0; cmdtosend[i]; i++)
{
free(cmdtosend[i]);
cmdtosend[i] = NULL;
}
free(cmdtosend);
cmdtosend = NULL;
exit(EXIT_FAILURE);
}
else
wait(NULL);
}
