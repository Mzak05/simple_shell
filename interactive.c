#include "shell.h"
/**
 * interactive - returns true if shell is interactive mode
 * @infffo: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_type *infffo)
{
	return (isatty(STDIN_FILENO) && infffo->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @caca: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char caca, char *delim)
{
	while (*delim)
		if (*delim++ == caca)
			return (1);
	return (0);
}

/**
 *_is_alpha - checks for alphabetic character
 *@caca: The character to input
 *Return: 1 if caca is alphabetic, 0 otherwise
 */

int _is_alpha(int caca)
{
	if ((caca >= 'a' && caca <= 'z') || (caca >= 'A' && caca <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_sti - converts a string to an integer
 *@achstr: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _sti(char *achstr)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  achstr[i] != '\0' && flag != 2; i++)
	{
		if (achstr[i] == '-')
			sign *= -1;

		if (achstr[i] >= '0' && achstr[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (achstr[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
