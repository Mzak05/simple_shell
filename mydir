#include "shell.h"
/**
 * _myexit - exits the shell
 * @infffo: Structure containing potential arguments
 *  Return: exits with a given exit status
 */
int _myexit(info_type *infffo)
{
	int exit_check;

	if (infffo->argv[1])  
	{
		exit_check = _errors_sti(infffo->argv[1]);
		if (exit_check == -1)
		{
			infffo->status = 2;
			print_error(infffo, "Illegal number: ");
			_eput_str(infffo->argv[1]);
			_eputchar('\n');
			return (1);
		}
		infffo->err_num = _errors_sti(infffo->argv[1]);
		return (-2);
	}
	infffo->err_num = -1;
	return (-2);
}

/**
 * _mydir - changes the current directory of the process
 * @infffo: Structure containing potential arguments
 *  Return: Always 0
 */
int _mydir(info_type *infffo)
{
	char *s, *dir, buffer[1024];
	int chdir_rt;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!infffo->argv[1])
	{
		dir = _get_env(infffo, "HOME=");
		if (!dir)
			chdir_rt = 
				chdir((dir = _get_env(infffo, "PWD=")) ? dir : "/");
		else
			chdir_rt = chdir(dir);
	}
	else if (_str_comp(infffo->argv[1], "-") == 0)
	{
		if (!_get_env(infffo, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_get_env(infffo, "OLDPWD=")), _putchar('\n');
		chdir_rt = 
			chdir((dir = _get_env(infffo, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_rt = chdir(infffo->argv[1]);
	if (chdir_rt == -1)
	{
		print_error(infffo, "can't cd to ");
		_eput_str(infffo->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenviro(infffo, "OLDPWD", _get_env(infffo, "PWD="));
		_setenviro(infffo, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @infffo: Structure containing potential arguments
 *  Return: Always 0
 */
int _myhelp(info_type *infffo)
{
	char **arg_arr;

	arg_arr = infffo->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
