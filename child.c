#include "shell.h"

/**
 * forkpid - kid
 * @tikchbila: tikchibila
 * @powerful: tksixnine
 * Return: 0
 */
int forkpid(char *powerful, char **tikchbila)
{
	pid_t child_pid;
	int status;
	int execve_status;
	char **envp = environ;

	child_pid = fork();
	if (child_pid == -1)
	{
		noway(1);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve_status = execve(powerful, tikchbila, envp);
		if (execve_status == -1)
			return (-1);
	}
	else
		wait(&status);

	return (0);
}
