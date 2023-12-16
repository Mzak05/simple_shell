#include "shell.h"
/**
 *_eput_str - print string
 * @achstr: printed sr
 *
 * Return: Nada
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
 * _eputchar - char to standarderr
 * @caca: char 
 * Return: On success 1.
 * On error -1
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
 * _put_fd - print caca
 * @caca: char
 * @fd: filedescriptor
 *
 * Return: 1 on success On error -1
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
 *_puts_fd - print string
 * @achstr: string
 * @fd: filedescriptor
 * Return: number of chars
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
