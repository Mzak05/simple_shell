#include "shell.h"
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
