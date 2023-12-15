#include "shell.h"

/**
 * getout - datas
 * @tikchbila: lo
 * @mahmoud: lo
 * @karim: lo
 * @ahmed: lo
 * @samir: lo
 */
void getout(char **tikchbila, char *mahmoud, char *karim, int ahmed, char *samir)
{
	free(mahmoud);
	free(tikchbila);
	free(karim);
	if (ahmed == 1)
		free(samir);
}

/**
 * getoutmini - lo
 * @cmdtosend: lo
 * @size: lo
 */
void getoutmini(char **cmdtosend, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		free(cmdtosend[i]);
		i++;
	}
	free(cmdtosend);
}
