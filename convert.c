#include "shell.h"
/**
 * _errors_sti - converts a string to an integer
 * @achstr: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _errors_sti(char *achstr)
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

/**
 * print_error - prints an error message
 * @infffo: the parameter & return info struct
 * @badstr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
void print_error(info_type *infffo, char *badstr)
{
	_eput_str(infffo->fname);
	_eput_str(": ");
	print_decimal(infffo->line_count, STDERR_FILENO);
	_eput_str(": ");
	_eput_str(infffo->argv[0]);
	_eput_str(": ");
	_eput_str(badstr);
}

/**
 * print_decimal - function prints a decimal (integer) number (base 10)
 * @inpp: the input
 * @fd: the filedescriptor to write to
 * Return: number of characters
 */
int print_decimal(int inpp, int fd)
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

/**
 * convert_number - converter function, a clone of itoa
 * @numbobo: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
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

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
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
