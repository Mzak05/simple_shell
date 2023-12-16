#include "shell.h"
/**
 **_strn_copy - copies a string
 *@desti: the destination string to be copied to
 *@sstr: the source string
 *@cc: the amount of characters to be copied
 *Return: the concatenated string
 */
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

/**
 **_strncat - concatenates two strings
 *@desti: the first string
 *@str_src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
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

/**
 **_str_chr - locates a character in a string
 *@sp: the string to be parsed
 *@sc: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_str_chr(char *sp, char sc)
{
	do {
		if (*sp == sc)
			return (sp);
	} while (*sp++ != '\0');

	return (NULL);
}
