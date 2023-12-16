#include "shell.h"
int _myexit(info_type *infffo)
{
	int exit_check;

	if (infffo->argv[1])  
	{
		exit_check = errorst(infffo->argv[1]);
		if (exit_check == -1)
		{
			infffo->status = 2;
			printerr(infffo, "Illegal number: ");
			_eput_str(infffo->argv[1]);
			_eputchar('\n');
			return (1);
		}
		infffo->err_num = errorst(infffo->argv[1]);
		return (-2);
	}
	infffo->err_num = -1;
	return (-2);
}

int helpmy(info_type *infffo)
{
	char **arg_arr;

	arg_arr = infffo->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
