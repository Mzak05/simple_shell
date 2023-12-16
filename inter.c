#include "shell.h"

int interactive(info_type *infffo)
{
	return (isatty(STDIN_FILENO) && infffo->readfd <= 2);
}

int is_delim(char caca, char *delim)
{
	while (*delim)
		if (*delim++ == caca)
			return (1);
	return (0);
}

int _is_alpha(int caca)
{
	if ((caca >= 'a' && caca <= 'z') || (caca >= 'A' && caca <= 'Z'))
		return (1);
	else
		return (0);
}

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
