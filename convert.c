#include "shell.h"
int errorst(char *achstr)
{
	int i = 0;
	unsigned long int result = 0;

	if (*achstr == '+')
		achstr++; 
	for (i = 0;  achstr[i] != '\0'; i++)
	{
		if (achstr[i] >= '0' && achstr[i] <= '9')
		{
			result *= 10;
			result += (achstr[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

void printerr(info_type *infffo, char *badstr)
{
	_eput_str(infffo->fname);
	_eput_str(": ");
	printdec(infffo->line_count, STDERR_FILENO);
	_eput_str(": ");
	_eput_str(infffo->argv[0]);
	_eput_str(": ");
	_eput_str(badstr);
}


int printdec(int inpp, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, c = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (inpp < 0)
	{
		_abs_ = -inpp;
		__putchar('-');
		c++;
	}
	else
		_abs_ = inpp;
	current = _abs_;
	for (i = 100000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			c++;
		}
		current %= i;
	}
	__putchar('0' + current);
	c++;

	return (c);
}

char *convert_number(long int numbobo, int base, int rayas)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = numbobo;

	if (!(rayas & CONVERT_UNSIGNED) && numbobo < 0)
	{
		n = -numbobo;
		sign = '-';

	}
	array = rayas & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do	{
		*--p = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

void remove_comments(char *bufbuf)
{
	int i;

	for (i = 0; bufbuf[i] != '\0'; i++)
		if (bufbuf[i] == '#' && (!i || bufbuf[i - 1] == ' '))
		{
			bufbuf[i] = '\0';
			break;
		}
}
