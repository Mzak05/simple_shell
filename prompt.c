#include "shell.h"

/**
 * pro - lo
 * @trf: lo
 * @lsp: lo
**/
void pro(struct stat trf, int lsp)
{
	fstat(lsp, &trf);

	if (S_ISCHR(trf.st_mode))
		_puts(PROMPT);
}

/**
 * _puts - zepol
 * @red: dd
 */
void _puts(char *red)
{
	unsigned int size;

	size = _strlen(red);

	write(STDOUT_FILENO, red, size);
}
