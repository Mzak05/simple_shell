#include "shell.h"
char **str_split(char *achstr, char *dli)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (achstr == NULL || achstr[0] == 0)
		return (NULL);
	if (!dli)
		dli = " ";
	for (i = 0; achstr[i] != '\0'; i++)
		if (!is_delim(achstr[i], dli) && (is_delim(achstr[i + 1], dli) || !achstr[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(achstr[i], dli))
			i++;
		k = 0;
		while (!is_delim(achstr[i + k], dli) && achstr[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = achstr[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
char **str_split2(char *achstr, char dli)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (achstr == NULL || achstr[0] == 0)
		return (NULL);
	for (i = 0; achstr[i] != '\0'; i++)
		if ((achstr[i] != dli && achstr[i + 1] == dli) ||
		    (achstr[i] != dli && !achstr[i + 1]) || achstr[i + 1] == dli)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (achstr[i] == dli && achstr[i] != dli)
			i++;
		k = 0;
		while (achstr[i + k] != dli && achstr[i + k] && achstr[i + k] != dli)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = achstr[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
