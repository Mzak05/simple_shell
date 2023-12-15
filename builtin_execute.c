#include "shell.h"
/**
**blexe - lopez
**@tikchbila: oeoe
**Return: info
**/
int blexe(char **tikchbila)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int i;

	built_s goku[] = {
		{"exit", exitsh},
		{"env", printenv},
		{NULL, NULL}
	};

	if (tikchbila[0] == NULL)
		return (1);

	length = _strlen(tikchbila[0]);

	num = snb(goku);
	for (i = 0; i < num; i++)
	{
		if (_strcmp(tikchbila[0], goku[i].name, length) == 0)
		{
			status = (goku[i].p)();
			return (status);
		}
	}
	return (1);
}

/**
**snb - iii
**@goku: ddd
**Return: nood
**/

int snb(built_s goku[])
{
	unsigned int i;

	i = 0;
	while (goku[i].name != NULL)
		i++;

	return (i);
}
