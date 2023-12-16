#include "shell.h"
int shell_loop(info_type *infffo, char **argv)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(infffo);
		if (interactive(infffo))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(infffo);
		if (r != -1)
		{
			set_info(infffo, argv);
			builtin_ret = find_builtin_cmd(infffo);
			if (builtin_ret == -1)
				find_command(infffo);
		}
		else if (interactive(infffo))
			_putchar('\n');
		free_info(infffo, 0);
	}
	write_history(infffo);
	free_info(infffo, 1);
	if (!interactive(infffo) && infffo->status)
		exit(infffo->status);
	if (builtin_ret == -2)
	{
		if (infffo->err_num == -1)
			exit(infffo->status);
		exit(infffo->err_num);
	}
	return (builtin_ret);
}
int find_builtin_cmd(info_type *infffo)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenvir},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _my_unsetenv},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_str_comp(infffo->argv[0], builtintbl[i].type) == 0)
		{
			infffo->line_count++;
			built_in_ret = builtintbl[i].func(infffo);
			break;
		}
	return (built_in_ret);
}

void find_command(info_type *infffo)
{
	char *path = NULL;
	int i, k;

	infffo->path = infffo->argv[0];
	if (infffo->linecount_flag == 1)
	{
		infffo->line_count++;
		infffo->linecount_flag = 0;
	}
	for (i = 0, k = 0; infffo->arg[i]; i++)
		if (!is_delim(infffo->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(infffo, _get_env(infffo, "PATH="), infffo->argv[0]);
	if (path)
	{
		infffo->path = path;
		fork_command(infffo);
	}
	else
	{
		if ((interactive(infffo) || _get_env(infffo, "PATH=")
			|| infffo->argv[0][0] == '/') && is_command(infffo, infffo->argv[0]))
			fork_command(infffo);
		else if (*(infffo->arg) != '\n')
		{
			infffo->status = 127;
			print_error(infffo, "not found\n");
		}
	}
}

void fork_command(info_type *infffo)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(infffo->path, infffo->argv, get_env(infffo)) == -1)
		{
			free_info(infffo, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(infffo->status));
		if (WIFEXITED(infffo->status))
		{
			infffo->status = WEXITSTATUS(infffo->status);
			if (infffo->status == 126)
				print_error(infffo, "Permission denied\n");
		}
	}
}
