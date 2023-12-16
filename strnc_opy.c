#include "shell.h"

char *_strn_copy(char *desti, char *sstr, int cc)
{
	int i, j;
	char *s = desti;

	i = 0;
	while (sstr[i] != '\0' && i < cc - 1)
	{
		desti[i] = sstr[i];
		i++;
	}
	if (i < cc)
	{
		j = i;
		while (j < cc)
		{
			desti[j] = '\0';
			j++;
		}
	}
	return (s);
}

char *_strncat(char *desti, char *sstr, int bu)
{
	int i, j;
	char *s = desti;

	i = 0;
	j = 0;
	while (desti[i] != '\0')
		i++;
	while (sstr[j] != '\0' && j < bu)
	{
		desti[i] = sstr[j];
		i++;
		j++;
	}
	if (j < bu)
		desti[i] = '\0';
	return (s);
}
char *_str_chr(char *sp, char sc)
{
	do {
		if (*sp == sc)
			return (sp);
	} while (*sp++ != '\0');

	return (NULL);
}
