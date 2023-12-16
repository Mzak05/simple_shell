#include "shell.h"
/**
 *_eput_str - prints an input string
 * @achstr: the string to be printed
 *
 * Return: Nothing
 */
void _eput_str(char *achstr)
{
	int i = 0;

	if (!achstr)
		return;
	while (achstr[i] != '\0')
	{
		_eputchar(achstr[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @caca: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char caca)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (caca == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (caca != BUF_FLUSH)
		buf[i++] = caca;
	return (1);
}

/**
 * _put_fd - writes the character c to given fd
 * @caca: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _put_fd(char caca, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (caca == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (caca != BUF_FLUSH)
		buf[i++] = caca;
	return (1);
}

/**
 *_puts_fd - prints an input string
 * @achstr: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _puts_fd(char *achstr, int fd)
{
	int i = 0;

	if (!achstr)
		return (0);
	while (*achstr)
	{
		i += _put_fd(*achstr++, fd);
	}
	return (i);
}
