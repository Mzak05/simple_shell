#include "shell.h"
int main(int ac, char **argv)
{
	info_type info[] = { INFO_INIT };
	int fdes = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fdes)
		: "r" (fdes));

	if (ac == 2)
	{
		fdes = open(argv[1], O_RDONLY);
		if (fdes == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eput_str(argv[0]);
				_eput_str(": 0: Can't open ");
				_eput_str(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fdes;
	}
	p_env_list(info);
	read_hist(info);
	shell_loop(info, argv);
	return (EXIT_SUCCESS);
}

