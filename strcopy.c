#include "shell.h"
char *_str_copy(char *desti, char *sbuf)
{
	int i = 0;

	if (desti == sbuf || sbuf == 0)
		return (desti);
	while (sbuf[i])
	{
		desti[i] = sbuf[i];
		i++;
	}
	desti[i] = 0;
	return (desti);
}

char *_str_dup(const char *dupstr)
{
	int length = 0;
	char *ret;

	if (dupstr == NULL)
		return (NULL);
	while (*dupstr++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--dupstr;
	return (ret);
}

void _puts(char *prstr)
{
	int i = 0;

	if (!prstr)
		return;
	while (prstr[i] != '\0')
	{
		_putchar(prstr[i]);
		i++;
	}
}

int _putchar(char cp)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (cp == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (cp != BUF_FLUSH)
		buf[i++] = cp;
	return (1);
}
